#ifndef KEYOBSERVERS_H
#define KEYOBSERVERS_H
#include "ECObserver.h"
#include "ECTextViewImp.h"
#include "Document.h"
#include <string>

class CursorObs : public ECObserver
{
public:
    CursorObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();

private:
    ECTextViewImp *pView;
    DocumentControl *docCtrl;
};

class EnterObs : public ECObserver
{
public:
    EnterObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();

private:
    ECTextViewImp *pView;
    DocumentControl *docCtrl;
};

class CharObs : public ECObserver
{
public:
    CharObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();

private:
    ECTextViewImp *pView;
    DocumentControl *docCtrl;
};

class DeleteObs : public ECObserver
{
public:
    DeleteObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();

private:
    ECTextViewImp *pView;
    DocumentControl *docCtrl;
};

class SwapModeObs : public ECObserver
{
public:
    SwapModeObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();
private:
    DocumentControl *docCtrl;
    ECTextViewImp *pView;
};

class UndoObs : public ECObserver
{
public:
    UndoObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();
private:
    DocumentControl *docCtrl;
    ECTextViewImp *pView;
};

class RedoObs : public ECObserver
{
public:
    RedoObs(ECTextViewImp *pView, DocumentControl *pCtrl) : pView(pView), docCtrl(pCtrl)
    {
        pView->Attach(this);
    }

    void Update();
    
private:
    DocumentControl *docCtrl;
    ECTextViewImp *pView;
};

#endif // KEYOBSERVERS_H