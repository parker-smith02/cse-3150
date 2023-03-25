// Created by Y. Wu, Jan 28, 2023
// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// (1): counting the number of subsets
int ECSubsetEnumCount(const std::vector<char> &vecChars)
{
  // return the number of subsets (without duplicates) of the vector of chars
  // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b) 
  // your code here ...
  int num = 1;
  map<char, int> frequency;
  for (char i : vecChars) {
    frequency[i]++;
  }
  for (pair<char, int> i : frequency) {
    num *= (i.second + 1);
  }
  return num;

}

// (2): enumerating the subsets, and store the found subsets in setSubsets
// Note: the found subsets can be of any order (but cannot contain duplicates)
// Also note: you should try to make your code as efficient as you can (avoid excessive data copying)

void powerSetHelp(const vector<char> &vecChars, int index, vector<vector<char> > &listSubsets, vector<char> curr) {
  if (index == vecChars.size()) {
    return;
  }
  
  sort(curr.begin(), curr.end());
  if (find(listSubsets.begin(), listSubsets.end(), curr) == listSubsets.end()) {
    listSubsets.push_back(curr);
  }

  for (int i = index + 1; i < vecChars.size(); i++) {
    curr.push_back(vecChars[i]);
    powerSetHelp(vecChars, i, listSubsets, curr);
    curr.pop_back();
  }
  return;
}

void ECSubsetEnum(const std::vector<char> &vecChars, std::vector<vector<char> > &listSubsets)
{
  // your code here
  vector<char> curr;
  powerSetHelp(vecChars, -1, listSubsets, curr);

}
