#ifndef DISPLAYNAME_H
#define DISPLAYNAME_H

#include <iostream>
#include "ECObserver.h"
#include <string>
#include "Document.h"

class EscapeObserver : public ECObserver
{
public:
    EscapeObserver(ECTextViewImp *pSubject, DocumentControl *pCtrl) : pSubject(pSubject), docCtrl(pCtrl)
    {
        pSubject->Attach(this);
    }

    void Update()
    {
        if (pSubject->GetPressedKey() == 27)
        {
            docCtrl->ClearRows();
            std::string str = "Escape pressed";
            docCtrl->InsertRowAt(0, str);
        }

        if (pSubject->GetPressedKey() == 17)
        {
            pSubject->Quit();
        }
    }

private:
    ECTextViewImp *pSubject;
    DocumentControl *docCtrl;
};

#endif // DISPLAYNAME_H