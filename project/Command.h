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
    std::stack <Command *> commandStack;
    std::stack <Command *> undoStack;
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


#endif // COMMAND_H
