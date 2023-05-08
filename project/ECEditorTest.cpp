// Test code for editor
#include "ECTextViewImp.h"
#include "KeyObservers.h"
#include <iostream>
#include <string>

using namespace std;

int myCounter = 0;

void bootstrapEditor(DocumentControl &docCtrl, std::string filename)
{
    std::string line;
    int row = 0;
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        while (std::getline(inFile, line))
        {
            docCtrl.InsertRowAt(row, line);
            row++;
        }
        inFile.close();
    }
}

int main(int argc, char *argv[])
{
    //
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string filename = argv[1];

    ECTextViewImp wndTest;
    TextDocument *doc = new TextDocument(&wndTest, filename);
    DocumentControl &docCtrl = doc->GetCtrl();
    CursorObs cursorObs(&wndTest, &docCtrl);
    EnterObs enterObs(&wndTest, &docCtrl);
    CharObs charObs(&wndTest, &docCtrl);
    DeleteObs deleteObs(&wndTest, &docCtrl);
    SwapModeObs swapModeObs(&wndTest, &docCtrl);
    UndoObs undoObs(&wndTest, &docCtrl);
    RedoObs redoObs(&wndTest, &docCtrl);

    bootstrapEditor(docCtrl, filename);
    wndTest.AddStatusRow("COMMAND MODE", "", true);


    

    wndTest.Show();


    delete doc;

    return 0;
}
