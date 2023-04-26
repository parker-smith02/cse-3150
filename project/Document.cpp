#include <iostream>
#include <string>
#include <vector>
#include "Document.h"


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

void DocumentControl::InsertCharAt(int row, int col, char ch)
{
    std::cout << "DocumentControl::InsertCharAt()" << std::endl;
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


//*******DOCUMENT********

void TextDocument::InsertRowAt(int row, std::string text)
{
    rows.insert(rows.begin() + row, text);
    RefreshView();
    
}

void TextDocument::AddRow(std::string text)
{
    rows.push_back(text);
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
    pView->InitRows();
    for (std::string row : rows)
    {
        pView->AddRow(row);
    }
}

void TextDocument::SetRow(int row, std::string text)
{
    rows[row] = text;
    RefreshView();
}

