//
//  ECCommand.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory() 
{
  // your code goes here

}

ECCommandHistory :: ~ECCommandHistory()
{
  // your code goes here
}

void ECCommandHistory::ExecuteCmd( ECCommand *pCmd ) {
  pCmd->Execute();
  commandStack.push(pCmd);
}

bool ECCommandHistory::Undo() {
  if (commandStack.empty()) {
    return false;
  }
  ECCommand *commandToUndo = commandStack.top();
  commandToUndo->UnExecute();
  undoStack.push(commandToUndo);
  commandStack.pop();
}

bool ECCommandHistory::Redo() {
  if (undoStack.empty()) {
    return false;
  }
  ECCommand *commandToRedo = undoStack.top();
  commandToRedo->Execute();
  commandStack.push(commandToRedo);
}

