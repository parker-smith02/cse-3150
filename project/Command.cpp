#include <iostream>
#include <string>
#include <vector>
#include "Command.h"
#include "Document.h"

class TextDocument;

MoveCursorCommand::MoveCursorCommand(ECTextViewImp *_pView, int _key, TextDocument &_pDoc) : pView(_pView), key(_key), pDoc(_pDoc) {}

void MoveCursorCommand::Execute()
{
    int cursorX = pView->GetCursorX();
    int cursorY = pView->GetCursorY();
    int lineLength = pDoc.GetRowLength(cursorY);
    int prevLineLength = pDoc.GetRowLength(cursorY - 1);
    int nextLineLength = pDoc.GetRowLength(cursorY + 1);

    switch (key)
    {

    case 1000: // left
        if (cursorX > 0)
        {
            pView->SetCursorX(cursorX - 1);
        }
        break;

    case 1001: // right
        if (lineLength > cursorX)
        {
            pView->SetCursorX(cursorX + 1);
        }
        break;

    case 1002: // up
        if (cursorY > 0)
        {
            pView->SetCursorY(cursorY - 1);
            if (prevLineLength < cursorX)
            {
                pView->SetCursorX(prevLineLength);
            }
        }
        break;

    case 1003: // down
        pView->SetCursorY(cursorY + 1);
        if (nextLineLength < cursorX)
        {
            pView->SetCursorX(nextLineLength);
        }
        break;
    }
}

void MoveCursorCommand::UnExecute()
{
}

void CommandHistory::Undo()
{
    while (!commandStack.empty())
    {
        if (commandStack.top()->CanUndo())
        {
            undoStack.push(commandStack.top());
            commandStack.top()->UnExecute();
        }
        commandStack.pop();
    }
}

void CommandHistory::Redo()
{
    while (!undoStack.empty())
    {
        if (undoStack.top()->CanUndo())
        {
            commandStack.push(undoStack.top());
            undoStack.top()->Execute();
        }
        undoStack.pop();
    }
}

void CommandHistory::Execute(Command *pCommand)
{
    pCommand->Execute();
    commandStack.push(pCommand);
}

EnterCommand::EnterCommand(ECTextViewImp &_pView, DocumentControl &_docCtrl) : pView(_pView), docCtrl(_docCtrl)
{
    originalRowNum = pView.GetCursorY();
}

void EnterCommand::Execute()
{
    int cursorX = pView.GetCursorX();
    int cursorY = pView.GetCursorY();
    if (cursorX == docCtrl.GetRowLength(cursorY))
    {
        docCtrl.InsertRowAt(cursorY + 1, "");
    }
    else
    {
        std::string curRow = docCtrl.GetRow(cursorY);
        std::string newRow = curRow.substr(0, cursorX);
        std::string newNextRow = curRow.substr(cursorX, curRow.length() - cursorX);
        docCtrl.SetRow(cursorY, newRow);
        docCtrl.InsertRowAt(cursorY + 1, newNextRow);
    }
    pView.SetCursorX(0);
    pView.SetCursorY(cursorY + 1);
}

void EnterCommand::UnExecute()
{
    std::string curRow = docCtrl.GetRow(originalRowNum);
    std::string prevRow = docCtrl.GetRow(originalRowNum + 1);
    std::string newRow = curRow + prevRow;
    docCtrl.SetRow(originalRowNum, newRow);
    docCtrl.DeleteRowAt(originalRowNum + 1);
    pView.SetCursorX(curRow.length());
    pView.SetCursorY(originalRowNum);
}

void InsertCharCommand::Execute()
{
    std::string curRow = docCtrl.GetRow(row);
    docCtrl.InsertCharAt(row, col, ch);
}

void InsertCharCommand::UnExecute()
{
    docCtrl.DeleteCharAt(row, col + 1);
}

DeleteCharCommand::DeleteCharCommand(DocumentControl &_docCtrl, int _row, int _col) : docCtrl(_docCtrl), row(_row), col(_col)
{
    charToDelete = docCtrl.GetDoc().GetRow(row)[col - 1];
}

void DeleteCharCommand::Execute()
{
    std::string curRow = docCtrl.GetRow(row);
    docCtrl.DeleteCharAt(row, col);
}

void DeleteCharCommand::UnExecute()
{
    docCtrl.InsertCharAt(row, col - 1, charToDelete);
}