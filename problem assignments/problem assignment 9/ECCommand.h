//
//  ECCommand.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECCommand_h
#define ECCommand_h

#include <vector>
#include <stack>

// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory();
    virtual ~ECCommandHistory();
    virtual bool Undo();
    virtual bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    
private:
    // your code goes here
    std::stack<ECCommand *> commandStack;
    std::stack<ECCommand *> undoStack;
};


#endif /* ECCommand_h */
