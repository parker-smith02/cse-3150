#include "KeyObservers.h"
#include <string>
#include <iostream>
#include "Command.h"

void CursorObs::Update()
{
    int key = pView->GetPressedKey();
    MoveCursorCommand *pCommand = new MoveCursorCommand(pView, key, docCtrl->GetDoc());
    docCtrl->Execute(pCommand);
}

void EnterObs::Update()
{
    int key = pView->GetPressedKey();
    if (key == 13)
    {
        EnterCommand *pCommand = new EnterCommand(*pView, *docCtrl);
        docCtrl->Execute(pCommand);
    }
}

void CharObs::Update()
{
    int key = pView->GetPressedKey();
    if (key > 27 && key < 127)
    {
        InsertCharCommand *pCommand = new InsertCharCommand(*docCtrl, key, pView->GetCursorY(), pView->GetCursorX());
        docCtrl->Execute(pCommand);
    }
}

void DeleteObs::Update()
{
    int key = pView->GetPressedKey();
    if (key == 127)
    {
        DeleteCharCommand *pCommand = new DeleteCharCommand(*docCtrl, pView->GetCursorY(), pView->GetCursorX());
        docCtrl->Execute(pCommand);
    }
}