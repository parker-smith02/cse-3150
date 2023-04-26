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