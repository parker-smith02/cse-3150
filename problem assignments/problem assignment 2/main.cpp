#include <iostream>

using namespace std;

extern string ECLongestPrefix(int numStrings, const std::string arrayStrings[]);


string testArr1[] = {"flower", "float", "florida"};
string testArr2[] = {"dog", "car", "test", "race"}; 


int main () {

    cout << ECLongestPrefix(3, testArr1) << endl;
     cout << ECLongestPrefix(3, testArr2) << endl;

    return 0;
}