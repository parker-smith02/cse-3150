//
//  ECCommand.cpp
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"
#include <iostream>

// ******************************************************
// Implement command history

ECCommandHistory ::ECCommandHistory() : commandStack(), undoStack()
{
  // your code goes here
}

ECCommandHistory ::~ECCommandHistory()
{
  // your code goes here
}

void ECCommandHistory::ExecuteCmd(ECCommand *pCmd)
{
  pCmd->Execute();
  commandStack.push(pCmd);
}

bool ECCommandHistory::Undo()
{
  if (commandStack.empty())
  {
    return false;
  }
  ECCommand *commandToUndo = commandStack.top();
  // std::cout << "commandToUndo: " << commandToUndo << std::endl;
  commandToUndo->UnExecute();
  // std::cout << "Un-Executed" << std::endl;
  undoStack.push(commandToUndo);
  commandStack.pop();
  // std::cout << "Removed from command stack" << std::endl;
  return true;
}

bool ECCommandHistory::Redo()
{
  if (undoStack.empty())
  {
    return false;
  }
  ECCommand *commandToRedo = undoStack.top();
  commandToRedo->Execute();
  commandStack.push(commandToRedo);
  undoStack.pop();
  return true;
}
