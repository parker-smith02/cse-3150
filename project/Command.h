#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <stack>
#include "ECTextViewImp.h"

class TextDocument;
class DocumentControl;

class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

class CommandHistory
{
public:
    CommandHistory() {}
    virtual ~CommandHistory() {}
    bool Undo();
    bool Redo();
    void Execute(Command *pCommand);

private:
    std::stack<Command *> commandStack;
    std::stack<Command *> undoStack;
};

class MoveCursorCommand : public Command
{
public:
    MoveCursorCommand(ECTextViewImp *_pView, int _key, TextDocument &_pDoc);

    virtual void Execute();

    virtual void UnExecute();

private:
    ECTextViewImp *pView;
    int key;
    TextDocument &pDoc;
};

class EnterCommand : public Command
{
public:
    EnterCommand(ECTextViewImp &_pView, DocumentControl &_docCtrl) : pView(_pView), docCtrl(_docCtrl) {}

    virtual void Execute();

    virtual void UnExecute();

private:
    DocumentControl &docCtrl;
    ECTextViewImp &pView;
};

class InsertCharCommand : public Command
{
public:
    InsertCharCommand(DocumentControl &_docCtrl, char _ch, int _row, int _col) : docCtrl(_docCtrl), ch(_ch), row(_row), col(_col) {}

    virtual void Execute();

    virtual void UnExecute();

private:
    DocumentControl &docCtrl;
    char ch;
    int row;
    int col;
};

class DeleteCharCommand : public Command
{
public:
    DeleteCharCommand(DocumentControl &_docCtrl, int _row, int _col) : docCtrl(_docCtrl), row(_row), col(_col) {}

    virtual void Execute();

    virtual void UnExecute();

private:
    DocumentControl &docCtrl;
    int row;
    int col;
};

#endif // COMMAND_H
