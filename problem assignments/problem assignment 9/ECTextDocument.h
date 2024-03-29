//
//  ECTextDocument.h
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>
#include <iostream>

class ECTextDocument;

// **********************************************************
// Implements Commands for editing

// your code goes here

class InsertTextCommand : public ECCommand
{
public:
    InsertTextCommand(ECTextDocument &_doc, int _pos, const std::vector<char> &_chars) : doc(_doc), pos(_pos), chars(_chars)
    {
        std::cout << "InsertTextCommand:: ";
        pChars(chars);
        std::cout << "pos: " << pos << std::endl;
    }

    void Execute();
    void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    std::vector<char> chars;
};

class RemoveTextCommand : public ECCommand
{
public:
    RemoveTextCommand(ECTextDocument &_doc, int _pos, int _len) : doc(_doc), pos(_pos), len(_len)
    {
        std::cout << "RemoveTextCommand:: ";
        std::cout << "pos: " << pos << " len: " << len << std::endl;
    }
    void Execute();
    void UnExecute();

private:
    std::vector<char> removed;
    ECTextDocument &doc;
    int pos;
    int len;
};

class CapTextCommand : public ECCommand
{
public:
    CapTextCommand(ECTextDocument &_doc, int _pos, int _len) : doc(_doc), pos(_pos), len(_len)
    {
        std::cout << "CapTextCommand:: ";
        std::cout << "pos: " << pos << " len: " << len << std::endl;
    }
    void Execute();
    void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    int len;
};

class LowerTextCommand : public ECCommand
{
public:
    LowerTextCommand(ECTextDocument &_doc, int _pos, int _len) : doc(_doc), pos(_pos), len(_len)
    {
        std::cout << "LowerTextCommand:: ";
        std::cout << "pos: " << pos << " len: " << len << std::endl;
    }
    void Execute();
    void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    int len;
};

// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:                                        // default constructor
    ECTextDocumentCtrl(ECTextDocument &docIn); // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char> &listCharsToIns); // insert a list of characters starting at position
    void RemoveTextAt(int pos, int lenToRemove);                         // remove a segment of characters  of lenToRemove starting from pos
    void CapTextAt(int pos, int lenToCap);                               // Capitalize the text of lenToCap long starting from pos
    void LowerTextAt(int pos, int lenToLower);                           // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                         // undo any change you did to the text
    bool Redo();                                                         // redo the change to the text

private:
    // your code
    ECCommandHistory cmdHistory;
    ECTextDocument &doc;
};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl(); // return document controller
    int GetDocLen() const { return listChars.size(); }
    char GetCharAt(int pos) const;       // get char at current position
    void InsertCharAt(int pos, char ch); // insert a single char at position
    void RemoveCharAt(int pos);          // erase a single char at position
    void CapCharAt(int pos);             // capitalize the char at position
    void LowerCharAt(int pos);           // lowercase the char at position

private:
    // your code
    std::vector<char> listChars;
    ECTextDocumentCtrl *docCtrl;
};

#endif /* ECTextDocument_h */
