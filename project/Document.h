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
    virtual ~DocumentControl();
    void InsertRowAt(int row, std::string text);
    void DeleteRowAt(int row);
    void InsertCharAt(int row, int col, char ch);
    void DeleteCharAt(int row, int col);
    void ClearRows();
    void Execute(Command *pCommand);
    int GetRowLength(int row);
    std::string GetRow(int row);
    void SetRow(int row, std::string text);
    TextDocument &GetDoc() { return pDoc; }
    int GetMode();
    void SwapMode();
    void Undo() { history.Undo(); }
    void Redo() { history.Redo(); }

private:
    TextDocument &pDoc;
    CommandHistory history;
};

class TextDocument : public ECObserver
{
public:
    TextDocument(ECTextViewImp *_pView, std::string _saveFile = "");

    void Save();

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
    void DeleteRowAt(int row);
    void InsertCharAt(int row, int col, char ch);
    void DeleteCharAt(int row, int col);
    int GetRowLength(int row);
    void AddRow(std::string text);
    void RefreshView();
    std::string GetRow(int row) { return rows[row]; }
    void SetRow(int row, std::string text);

    DocumentControl &GetCtrl() { return docCtrl; }
    int GetMode() { return mode; }
    int SetMode(int _mode) { this->mode = _mode; }
    std::string GetSaveFile() { return saveFile; }
    void WrapRow(int row, char ch);

private:
    void LoadKeywords();
    bool IsKeyword(std::string word);
    std::vector<std::string> Split(std::string str);

    DocumentControl docCtrl;
    ECTextViewImp *pView;
    std::vector<std::string> rows;
    std::vector<std::string> keywords;
    std::string saveFile;
    int mode; // 0: command, 1: edit
    std::vector<int> wrappedRows;   // Vector contains an integer for each row, 0: not wrapped, 1: wrapped
};

#endif // DOCUMENT_H