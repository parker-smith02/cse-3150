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
class InsertTextCommand : public ECCommand {
public:

private:

};



// **********************************************************
// Controller for text document
ECTextDocumentCtrl :: ECTextDocumentCtrl() {
  doc = ECTextDocument();
}


ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) : doc(docIn)
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  // your code

}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  // your code
}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
  // your code
}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
  // your code
}

bool ECTextDocumentCtrl :: Undo()
{
  // your code
}

bool ECTextDocumentCtrl :: Redo()
{
  // your code

}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument() 
{
  docCtrl = new ECTextDocumentCtrl(*this);
}

ECTextDocument :: ~ECTextDocument()
{
  delete docCtrl;
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return *docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  // your code here
  vector<char>::iterator it = listChars.begin() + pos;
  listChars.insert(it, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
  // your code here
  vector<char>::iterator it = listChars.begin() + pos;
  listChars.erase(it);
}

void ECTextDocument :: CapCharAt(int pos)
{
  // your code here
  for (int i = 0; i < listChars.size(); i++)
  {
    if (i == pos) {
      listChars[i] = toupper(listChars[i]);
    }
  }
}

void ECTextDocument :: LowerCharAt(int pos)
{
  // your code here
  for (int i = 0; i < listChars.size(); i++)
  {
    if (i == pos) {
      listChars[i] = tolower(listChars[i]);
    }
  }
}

