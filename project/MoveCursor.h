#ifndef MOVECURSOR_H
#define MOVECURSOR_H

#include <iostream>
#include <string>
#include <vector>
#include "ECObserver.h"
#include "ECTextViewImp.h"

class MoveCursorObserver : public ECObserver
{
public:
    MoveCursorObserver(ECTextViewImp *_pSubject) : pSubject(_pSubject)
    {
        pSubject->Attach(this);
    }

    void Update();

private:
    ECTextViewImp *pSubject;
};

#endif // MOVECURSOR_H
