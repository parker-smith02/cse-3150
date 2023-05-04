#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "ECTextViewImp.h"
#include "Command.h"
class TextDocument;

class DocumentControl
{
public:
    DocumentControl(TextDocument &doc);
    void InsertRowAt(int row, std::string text);
    void InsertCharAt(int row, int col, char ch);
    void DeleteCharAt(int row, int col);
    void ClearRows();
    void Execute(Command *pCommand);
    int GetRowLength(int row);
    std::string GetRow(int row);
    void SetRow(int row, std::string text);
    TextDocument &GetDoc() { return pDoc; }

private:
    TextDocument &pDoc;
    CommandHistory history;
};

class TextDocument : public ECObserver
{
public:
    TextDocument(ECTextViewImp *_pView) : pView(_pView), docCtrl(*this)
    {
        pView->Attach(this);
        rows = std::vector<std::string>();
    }

    virtual void Update()
    {
    }

    void ClearRows()
    {
        rows = std::vector<std::string>();
        pView->InitRows();
        pView->ClearColor();
    }

    void InsertRowAt(int row, std::string text);
    void InsertCharAt(int row, int col, char ch);
    void DeleteCharAt(int row, int col);
    int GetRowLength(int row);
    void AddRow(std::string text);
    void RefreshView();
    std::string GetRow(int row) { return rows[row]; }
    void SetRow(int row, std::string text);

    DocumentControl &GetCtrl() { return docCtrl; }

private:
    DocumentControl docCtrl;
    ECTextViewImp *pView;

    std::vector<std::string> rows;
};

#endif // DOCUMENT_H