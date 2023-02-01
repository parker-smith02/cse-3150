//
//  ValidPalindrome.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <iostream>
#include <cstdio>

using namespace std;

// Function to test if the input string is a valid palindrome
// Note: only consider alphanumeric symbols and ignore cases
bool IsValidPalindrome(const string &strInput)
{
    // your code go here ...
    string input = strInput;
    for (int left = 0, right = input.size() - 1; left < right; left++, right--) {
    while (!isalnum(input[left]) && left < right) left++;
    while (!isalnum(input[right]) && left < right) right--;
    if (toupper(input[left]) != toupper(input[right])) return false;
    }
    return true;
}


