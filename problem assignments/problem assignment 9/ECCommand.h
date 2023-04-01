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
#include <iostream>
#include <stack>

// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
    void pChars(std::vector<char> &chars)
    {
        for (auto x : chars)
        {
            std::cout << x;
        }
        std::cout << std::endl;
    }
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
    void ExecuteCmd(ECCommand *pCmd);

private:
    // your code goes here
    std::stack<ECCommand *> commandStack;
    std::stack<ECCommand *> undoStack;
};

#endif /* ECCommand_h */
