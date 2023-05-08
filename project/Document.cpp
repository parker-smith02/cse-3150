#include <iostream>
#include <string>
#include <vector>
#include "Document.h"
#include <sstream>
#include <ostream>

//*******DOCUMENT CONTROL********

void DocumentControl::Execute(Command *pCommand) { history.Execute(pCommand); }

DocumentControl::DocumentControl(TextDocument &doc) : pDoc(doc)
{
    history = CommandHistory();
}


void DocumentControl::InsertRowAt(int row, std::string text)
{
    pDoc.InsertRowAt(row, text);
}

void DocumentControl::DeleteRowAt(int row)
{
    pDoc.DeleteRowAt(row);
}

void DocumentControl::InsertCharAt(int row, int col, char ch)
{
    pDoc.InsertCharAt(row, col, ch);
}

void DocumentControl::DeleteCharAt(int row, int col)
{
    pDoc.DeleteCharAt(row, col);
}

void DocumentControl::ClearRows()
{
    pDoc.ClearRows();
}

int DocumentControl::GetRowLength(int row)
{
    return pDoc.GetRowLength(row);
}

std::string DocumentControl::GetRow(int row)
{
    return pDoc.GetRow(row);
}

void DocumentControl::SetRow(int row, std::string text)
{
    pDoc.SetRow(row, text);
}

int DocumentControl::GetMode()
{
    return pDoc.GetMode();
}

void DocumentControl::SwapMode()
{
    if (GetMode() == 0)
    {
        history.Reset();
    }

    pDoc.SetMode(GetMode() == 0 ? 1 : 0);
}

//*******DOCUMENT********
TextDocument::TextDocument(ECTextViewImp *_pView, std::string _saveFile) : pView(_pView), docCtrl(*this), saveFile(_saveFile)
{
    pView->Attach(this);
    rows = std::vector<std::string>();
    mode = 0;
    LoadKeywords();
}

void TextDocument::Save()
{
    pView->AddStatusRow(saveFile, "", 1);
    std::ofstream file;
    file.open("./" + saveFile, std::ofstream::out | std::ofstream::trunc);
    for (std::string row : rows)
    {
        file << row << std::endl;
    }
    file.close();
}

void TextDocument::InsertRowAt(int row, std::string text)
{
    if (rows.size() >= row)
    {
        rows.insert(rows.begin() + row, text);
        wrappedRows.insert(wrappedRows.begin() + row, 0);
        RefreshView();
    }
}

void TextDocument::DeleteRowAt(int row)
{
    if (rows.size() >= row)
    {
        rows.erase(rows.begin() + row);
        RefreshView();
    }
}

void TextDocument::InsertCharAt(int row, int col, char ch)
{
    if (rows.size() >= row)
    {
        bool flag = false;
        int rowSize = rows[row].length();
        bool wrapped = false;
        if (rowSize >= pView->GetColNumInView() - 1)
        {
            if (col != rowSize)
            {
                char temp = rows[row][col];
                rows[row][col] = ch;
                ch = temp;
                flag = true;
            }
            WrapRow(row, ch);
            row++;
            col = 0;
            wrapped = true;
        }
        rows[row].insert(col, 1, ch);
        RefreshView();
        int oldX = pView->GetCursorX();
        pView->SetCursorX(col + 1);
        if (wrapped)
        {
            pView->SetCursorY(pView->GetCursorY() + 1);
            pView->SetCursorX(col + 1);
        }
    }
}

void TextDocument::AddRow(std::string text)
{
    rows.push_back(text);
    wrappedRows.push_back(0);
    pView->AddRow(text);
}

int TextDocument::GetRowLength(int row)
{
    if (rows.size() > 0)
    {
        return rows[row].length();
    }
    return 0;
}

void TextDocument::RefreshView()
{
    pView->ClearColor();
    int rowPos;
    int rowNum = 0;

    pView->InitRows();
    for (std::string row : rows)
    {
        rowPos = 0;
        pView->AddRow(row);

        // check for highlighting
        for (std::string word : Split(row))
        {
            if (IsKeyword(word))
            {
                pView->SetColor(rowNum, rowPos, rowPos + word.length(), TEXT_COLOR_BLUE);
            }
            rowPos += word.length() + 1;
        }
        rowNum++;
    }
}

void TextDocument::SetRow(int row, std::string text)
{
    rows[row] = text;
    RefreshView();
}

void TextDocument::DeleteCharAt(int row, int col)
{
    if (row == 0 && col == 0)
    {
        return;
    }
    if (rows.size() >= row && col > 0)
    {
        rows[row].erase(col - 1, 1);
        pView->SetCursorX(col - 1);
    }
    else if (col <= 0 && rows.size() >= row)
    {
        pView->SetCursorY(row - 1);

        pView->SetCursorX(rows[row - 1].length());
        std::string rightOfCursor = rows[row];
        std::string newRowAbove = rows[row - 1] + rightOfCursor;
        SetRow(row - 1, newRowAbove);
        rows.erase(rows.begin() + row);
    }
    RefreshView();
}

void TextDocument::LoadKeywords()
{
    std::string line;
    std::ifstream myfile("keywords.txt");
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            keywords.push_back(line);
        }
        myfile.close();
    }
}

bool TextDocument::IsKeyword(std::string word)
{
    for (std::string keyword : keywords)
    {
        if (keyword == word)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> TextDocument::Split(std::string str)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, ' '))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void TextDocument::WrapRow(int row, char ch) // takes in ORIGINAL row
{
    std::string newRow = "";
    if (wrappedRows[row + 1] == 1)
    {
        return;
    }
    else
    {
        InsertRowAt(row + 1, newRow);
        wrappedRows[row + 1] = 1;
    }
}

bool TextDocument::IsWrappedRow(int row)
{
    return wrappedRows[row] == 1;
}