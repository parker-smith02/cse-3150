// Usage: ./GetFileLength  <file to calculate length>
// Read a file as given as the first parameter, count the length of the file and output it
// Here, length of a line is the number of characters in the line (i.e., ignoring special characters like newline)
// Length of the file is the sum of the lengths of all lines
// If no file or bad file is provided, just quit
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char const *argv[])
{

    if (argc != 2) {
        cout <<"Wrong number of arguments" << endl;
        return 1;
    }
    // Your code goes here	
   // open file
   ifstream f(argv[1]);
   if (f.is_open()) {
   // your code here
    string line;
    int len = 0;
    while (getline(f, line)) {
        len += line.length();
    }
    cout << len << endl;
   } else {
    cout << "Bad file." << endl;
    return 1;
   }
   // note: when you read from file, if you reach the end of the file, f.eof() will be true
   return 0;
}