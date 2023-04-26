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

bool CommandHistory::Undo()
{
    commandStack.top()->UnExecute();
    undoStack.push(commandStack.top());
}

bool CommandHistory::Redo()
{
    undoStack.top()->Execute();
    commandStack.push(undoStack.top());
}

void CommandHistory::Execute(Command *pCommand)
{
    pCommand->Execute();
    commandStack.push(pCommand);
}

void EnterCommand::Execute()
{
    int cursorX = pView.GetCursorX();
    int cursorY = pView.GetCursorY();
    if (cursorX == docCtrl.GetRowLength(cursorY))
    {
        docCtrl.InsertRowAt(cursorY + 1, "");
        pView.SetCursorX(0);
        pView.SetCursorY(cursorY + 1);
    }
    else
    {
        std::string curRow = docCtrl.GetRow(cursorY);
        std::string newRow = curRow.substr(0, cursorX);
        std::string newNextRow = curRow.substr(cursorX, curRow.length() - cursorX);
        docCtrl.SetRow(cursorY, newRow);
        docCtrl.InsertRowAt(cursorY + 1, newNextRow);
    }
}

void EnterCommand::UnExecute()
{
}