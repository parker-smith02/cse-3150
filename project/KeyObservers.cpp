#include "KeyObservers.h"
#include <string>
#include <iostream>
#include "Command.h"
#include "Document.h"

void CursorObs::Update()
{
    int key = pView->GetPressedKey();
    MoveCursorCommand *pCommand = new MoveCursorCommand(pView, key, docCtrl->GetDoc());
    docCtrl->Execute(pCommand);
}

void EnterObs::Update()
{
    int key = pView->GetPressedKey();
    if (key == 13 && docCtrl->GetMode() == 1)
    {
        EnterCommand *pCommand = new EnterCommand(*pView, *docCtrl);
        docCtrl->Execute(pCommand);
    }
}

void CharObs::Update()
{
    int key = pView->GetPressedKey();
    if (key > 27 && key < 127 && docCtrl->GetMode() == 1)
    {
        InsertCharCommand *pCommand = new InsertCharCommand(*docCtrl, key, pView->GetCursorY(), pView->GetCursorX());
        docCtrl->Execute(pCommand);
    }
}

void DeleteObs::Update()
{
    int key = pView->GetPressedKey();
    if (key == 127 && docCtrl->GetMode() == 1 && pView->GetCursorX() > 0 && pView->GetCursorY() >= 0)
    {
        DeleteCharCommand *pCommand = new DeleteCharCommand(*docCtrl, pView->GetCursorY(), pView->GetCursorX());
        docCtrl->Execute(pCommand);
    }
}

void SwapModeObs::Update()
{
    int key = pView->GetPressedKey();
    int curMode = docCtrl->GetMode();
    if (curMode == 0 && key == 105)
    {
        docCtrl->SwapMode();
        pView->ClearStatusRows();
        pView->AddStatusRow("EDIT MODE", std::to_string(curMode), true);
    } else if (curMode == 1 && (key == 27 || key == 1))
    {
        docCtrl->SwapMode();
        pView->ClearStatusRows();
        pView->AddStatusRow("COMMAND MODE", std::to_string(curMode) + "TEST", true);
    }
}

void UndoObs::Update()
{
    int key = pView->GetPressedKey();
    if (key == CTRL_Z && docCtrl->GetMode() == 0)
    {
        docCtrl->Undo();
    }
}
void RedoObs::Update()
{
    int key = pView->GetPressedKey();
    if (key == CTRL_Y && docCtrl->GetMode() == 0)
    {
        docCtrl->Redo();
    }
}