//
//  ECTextDocument.cpp
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands

// your code goes here
void InsertTextCommand::Execute()
{
  // std::cout << "InsertTextCommand::Execute" << doc.GetDocLen() << std::endl;
  for (int i = pos; i < chars.size() + pos; i++)
  {
    // std::cout << "IN LOOP";
    doc.InsertCharAt(i, chars[i - pos]);
  }
}

void InsertTextCommand::UnExecute()
{
  for (int i = 0; i < chars.size(); i++)
  {
    std::cout << i << std::endl;
    doc.RemoveCharAt(pos);
  }
}

void RemoveTextCommand::Execute()
{
  if (len > doc.GetDocLen())
  {
    return;
  }
  for (int i = 0; i < len; i++)
  {
    removed.push_back(doc.GetCharAt(pos));
    doc.RemoveCharAt(pos);
  }
}

void RemoveTextCommand::UnExecute()
{
  for (int i = len; i >= 0; i--)
  {
    std::cout << i << std::endl;
    doc.InsertCharAt(pos, removed[i]);
  }
}

void CapTextCommand::Execute()
{
  for (int i = 0; i < len; i++)
  {
    doc.CapCharAt(i + pos);
  }
}

void CapTextCommand ::UnExecute()
{
  for (int i = 0; i < len; i++)
  {
    doc.LowerCharAt(i + pos);
  }
}

void LowerTextCommand ::Execute()
{
  for (int i = 0; i < len; i++)
  {
    doc.LowerCharAt(i + pos);
  }
}

void LowerTextCommand ::UnExecute()
{
  for (int i = 0; i < len; i++)
  {
    doc.CapCharAt(i + pos);
  }
}
// **********************************************************
// Controller for text document

ECTextDocumentCtrl ::ECTextDocumentCtrl(ECTextDocument &docIn) : doc(docIn)
{
  cmdHistory = ECCommandHistory();
}

ECTextDocumentCtrl ::~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl ::InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  // your code
  // std::cout << "CONTROL INSERT" << std::endl;
  InsertTextCommand *cmd = new InsertTextCommand(doc, pos, listCharsToIns);
  cmdHistory.ExecuteCmd(cmd);
}

void ECTextDocumentCtrl ::RemoveTextAt(int pos, int lenToRemove)
{
  // your code
  RemoveTextCommand *cmd = new RemoveTextCommand(doc, pos, lenToRemove);
  cmdHistory.ExecuteCmd(cmd);
}

void ECTextDocumentCtrl ::CapTextAt(int pos, int lenToCap)
{
  // your code
  CapTextCommand *cmd = new CapTextCommand(doc, pos, lenToCap);
  cmdHistory.ExecuteCmd(cmd);
}

void ECTextDocumentCtrl ::LowerTextAt(int pos, int lenToLower)
{
  // your code
  LowerTextCommand *cmd = new LowerTextCommand(doc, pos, lenToLower);
  cmdHistory.ExecuteCmd(cmd);
}

bool ECTextDocumentCtrl ::Undo()
{
  // your code
  return cmdHistory.Undo();
}

bool ECTextDocumentCtrl ::Redo()
{
  // your code
  return cmdHistory.Redo();
}

// **********************************************************
// Document for text document

ECTextDocument::ECTextDocument()
{
  docCtrl = new ECTextDocumentCtrl(*this);
}

ECTextDocument::~ECTextDocument()
{
  delete docCtrl;
}

ECTextDocumentCtrl &ECTextDocument ::GetCtrl()
{
  return *docCtrl;
}

char ECTextDocument::GetCharAt(int pos) const
{
  return listChars[pos];
}

void ECTextDocument::InsertCharAt(int pos, char ch)
{
  // your code here
  // std::cout << "INSERT CHAR AT" << std::endl;
  vector<char>::iterator it = listChars.begin() + pos;
  listChars.insert(it, ch);
  for (auto x : listChars)
  {
    // std::cout << x << " ";
  }
  // std::cout << std::endl;
}

void ECTextDocument::RemoveCharAt(int pos)
{
  // your code here
  vector<char>::iterator it = listChars.begin() + pos;
  listChars.erase(it);
}

void ECTextDocument::CapCharAt(int pos)
{
  // your code here
  listChars[pos] = toupper(listChars[pos]);
}

void ECTextDocument::LowerCharAt(int pos)
{
  // your code here
  listChars[pos] = tolower(listChars[pos]);
}
