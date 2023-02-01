#include "ECLongestPrefix.h" 
#include <iostream>
#include <string>

using namespace std;

// Implement the longest prefix function here...
string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  // Replace with your own code here...
  if (numStrings == 1) return arrayStrings[0];
  if (numStrings == 0) return "";
  string prefix;
  int index = 1;

  while (index < 200) {
    prefix = arrayStrings[0].substr(0, index);
    for(int i=0; i<numStrings; ++i) {
      if (prefix != arrayStrings[i].substr(0, index)) {
        return arrayStrings[0].substr(0, index - 1);
      }
    }
    index++;
  }
  return prefix;
}

