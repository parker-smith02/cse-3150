#include <iostream>
#include "ECObserver.h"
#include "ECTextViewImp.h"



class EscapeObserver : public ECObserver
{
    public:
        EscapeObserver(ECTextViewImp *pSubject) : pSubject(pSubject)
        {
            pSubject->Attach(this);
        }

        void Update()
        {
            if (pSubject->GetPressedKey() == 27)
                pSubject->InitRows();
                pSubject->ClearColor();
                pSubject->AddRow("Parker Smith");
                pSubject->SetCursorY(pSubject->GetCursorY() + 1);
            
            if (pSubject->GetPressedKey() == 17) {
                
                pSubject->Quit();
            }
        }

    private:
        ECTextViewImp *pSubject;
};