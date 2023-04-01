#include <iostream>

using namespace std;

extern string ECLongestPrefix(int numStrings, const std::string arrayStrings[]);


string testArr1[] = {"flower", "float", "florida"};
string testArr2[] = {"dog", "car", "test", "race"}; 
string testArr3[] = {"common", "comm on"};
string testArr4[] = {"!@#$", "!@#$%", "!@#$%^"};
string testArr5[] = {"Testing"};
string testArr6[] = {"Testing", "Testingthis"};


int main () {

    cout << ECLongestPrefix(3, testArr1) << endl;
    cout << ECLongestPrefix(3, testArr2) << endl;
    cout << ECLongestPrefix(2, testArr3) << endl;
    cout << ECLongestPrefix(3, testArr4) << endl;
    cout << ECLongestPrefix(2, testArr6) << endl;
    

    return 0;
}