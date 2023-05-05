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
    virtual bool CanUndo() { return true; }
};

class CommandHistory
{
public:
    CommandHistory() {}
    virtual ~CommandHistory() {}
    void Undo();
    void Redo();
    void Execute(Command *pCommand);
    void Reset()
    {
        commandStack = std::stack<Command *>();
        undoStack = std::stack<Command *>();
    }

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

    virtual bool CanUndo() { return false; }

private:
    ECTextViewImp *pView;
    int key;
    TextDocument &pDoc;
};

class EnterCommand : public Command
{
public:
    EnterCommand(ECTextViewImp &_pView, DocumentControl &_docCtrl);

    virtual void Execute();

    virtual void UnExecute();

    virtual bool CanUndo() { return true; }

private:
    DocumentControl &docCtrl;
    ECTextViewImp &pView;
    int originalRowNum;
};

class InsertCharCommand : public Command
{
public:
    InsertCharCommand(DocumentControl &_docCtrl, char _ch, int _row, int _col) : docCtrl(_docCtrl), ch(_ch), row(_row), col(_col) {}

    virtual void Execute();

    virtual void UnExecute();

    virtual bool CanUndo() { return true; }

private:
    DocumentControl &docCtrl;
    char ch;
    int row;
    int col;
};

class DeleteCharCommand : public Command
{
public:
    DeleteCharCommand(DocumentControl &_docCtrl, int _row, int _col);

    virtual void Execute();

    virtual void UnExecute();

    virtual bool CanUndo() { return true; }

private:
    DocumentControl &docCtrl;
    int row;
    int col;
    char charToDelete;
};

#endif // COMMAND_H
