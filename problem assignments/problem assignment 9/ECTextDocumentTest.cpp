//
//  ECTextDocumentTest.cpp
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include <iostream>
#include "ECTextDocument.h"

using namespace std;

static void Test1()
{
    //
    ECTextDocument doc;
    ECTextDocumentCtrl &docCtrl = doc.GetCtrl();
    vector<char> listText1;
    listText1.push_back('a');
    listText1.push_back('b');
    listText1.push_back('c');
    listText1.push_back('d');
    listText1.push_back('e');
    docCtrl.InsertTextAt(0, listText1);
    vector<char> listText2;
    listText2.push_back('f');
    listText2.push_back('g');
    listText2.push_back('h');
    int posIns = 2;
    docCtrl.InsertTextAt(posIns, listText2);
    // int lenDel = 2;
    // docCtrl.RemoveTextAt( posIns, lenDel );
    int posCap = 2;
    int lenCap = 5;
    docCtrl.CapTextAt(posCap, lenCap);
    int posLow = 3;
    int lenLow = 2;
    docCtrl.LowerTextAt(posLow, lenLow);

    cout << "Text: ";
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;

    // try undo/redo
    docCtrl.Undo();
    cout << "After undo, text: ";
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;

    docCtrl.Redo();
    cout << "After redo, text: ";
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
}
void dump(ECTextDocument &doc)
{
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
}
static void test2()
{
    ECTextDocument doc;
    ECTextDocumentCtrl &docCtrl = doc.GetCtrl();
    vector<char> listText1;
    listText1.push_back('a');
    listText1.push_back('b');
    listText1.push_back('c');
    listText1.push_back('d');
    listText1.push_back('e');
    docCtrl.InsertTextAt(0, listText1);
    cout << "Text: ";
    dump(doc);
    vector<char> listText2;
    listText2.push_back('f');
    listText2.push_back('g');
    listText2.push_back('h');
    int posIns = 2;
    docCtrl.InsertTextAt(posIns, listText2);
    cout << "Text: ";
    dump(doc);
    docCtrl.RemoveTextAt(2, 3);
    cout << "Text after remove: ";
    dump(doc);
    docCtrl.Undo();
    cout << "After undo, text: ";
    dump(doc);
    docCtrl.Redo();
    cout << "After redo, text: ";
    dump(doc);
    docCtrl.CapTextAt(2, 3);
    dump(doc);
    docCtrl.Undo();
    dump(doc);
    docCtrl.Redo();
    dump(doc);
    docCtrl.LowerTextAt(2, 3);
    dump(doc);
    docCtrl.Undo();
    dump(doc);
    docCtrl.Redo();
    dump(doc);
    docCtrl.InsertTextAt(6, vector<char>{'x', 'y', 'z'});
    dump(doc);
}

static void test3()
{
    ECTextDocument doc;
    ECTextDocumentCtrl &docCtrl = doc.GetCtrl();
    docCtrl.InsertTextAt(0, vector<char>{'a', 'b'});
    docCtrl.InsertTextAt(2, vector<char>{'c'});
    docCtrl.InsertTextAt(3, vector<char>{'d'});
    docCtrl.InsertTextAt(4, vector<char>{'e'});
    // cout << "Len before undo 1: " << doc.GetDocLen() << endl;
    docCtrl.Undo();
    // cout << "Len before undo 2: " << doc.GetDocLen() << endl;
    // docCtrl.Undo();
    // cout << "Len after undo 3: " << doc.GetDocLen() << endl;
    docCtrl.InsertTextAt(4, vector<char>{'e'});
    docCtrl.Undo();
    docCtrl.Undo();
    docCtrl.InsertTextAt(3, vector<char>{'d'});
    docCtrl.CapTextAt(3, 1);
    dump(doc);
}

int main()
{
    // test code
    Test1();

    return 0;
}
