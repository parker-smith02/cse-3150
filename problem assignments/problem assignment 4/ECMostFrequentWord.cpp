// Created by Y. Wu, Jan 28, 2023
// Given a string, find the most frequent word; if there is a tie, choose alphabetically smallest
// Word: consecutive alphanumerical symbols; that is, treat all non-alphanumerical symbols as separators
// for example, for "I have bad dreams that have bad feelings", return "bad"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool mapCompare (pair<string, int> el1, pair<string, int> el2) {
  if (el1.second == el2.second) {
    return (el1.first.length() > el2.first.length());
  }
  return (el1.second < el2.second);
}

string ECMostFrequentWord(const string &strText)
{
  // your code here
  if (strText == "") {return strText;}
  std::map<std::string, int> counts;
  string stringCopy = strText;
  for (int i = 0; i < stringCopy.length(); i++) {
    if (!isalnum(stringCopy[i])) {
      stringCopy[i] = ' ';
    }
  }

  vector<string> stringArr;
  istringstream ss(stringCopy);
  string word;
  while (ss >> word) {
    stringArr.push_back(word);
  }

  for (string w : stringArr) {
    if (!counts[w]) {
      counts[w] = 1;
    } else {
      counts[w]++;
    }
  }
  map<string, int>::iterator max = max_element(counts.begin(), counts.end(), mapCompare);
  return max->first;
}


