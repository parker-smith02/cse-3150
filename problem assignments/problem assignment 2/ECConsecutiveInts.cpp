//
//  ECConsecutiveInts.cpp
//
//
//  Created by Yufeng Wu on 1/15/23.
//
//

#include <iostream>
#include <string>
using namespace std;

// Test whether strInput is a string composed of consecutive and increasing integers (in decimal formats)
// Return true if yes and false otherwise (return false if there are unexpected characters)
// For example, 1234578 would return false, while 1213141516 would return true (12 13 14 15 16)
// You may assume the integers is at most 999999 and there is no any seperators between numbers
// You may also assume integers are all non-negatives

// Tip: try to use library functions instead of writing a lot of code yourself
// functions in C++ string you may find useful:
// substr: extract a substring from a string
// stoi:  convert string to integer (be careful about how to handle exception)
// and so on..

bool ECConsecutiveInts(const string &strInput)
{
  // your code  here
  // find first number, concatinate successive numbers to the string until it equals input string

  int len = strInput.length();
  int firstNum, nextNum;
  string newStr;

  for (int i = 0; i < len / 2; i++)
  {
    try
    {
      firstNum = stoi(strInput.substr(0, i + 1));
    }
    catch (...)
    {
      return false;
    }
    newStr = strInput.substr(0, i + 1);
    nextNum = firstNum;
    while (newStr.length() < len)
    {
      nextNum++;
      newStr += to_string(nextNum);
    }
    if (newStr == strInput)
      return true;
  }
  return false;
}
