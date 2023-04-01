#include <iostream>
#include "ECArrayofStrings.h"

using namespace std;

ECArrayofStrings ::ECArrayofStrings()
{
}

ECArrayofStrings ::~ECArrayofStrings()
{
  // your code goes here
}

void ECArrayofStrings ::AddString(const string &strToAdd)
{
  // your code goes here
  vec.push_back(strToAdd);
}

int ECArrayofStrings ::GetNumofStrings() const
{
  // your code goes here
  return vec.size();
}

int ECArrayofStrings ::GetMaxLen() const
{
  // your code goes here
  int biggest = 0;
  for (auto i : vec)
  {
    int len = i.length();
    if (len > biggest)
      biggest = len;
  }
  return biggest;
}

string ECArrayofStrings ::GetLongestCommonPrefixofTwo(string s1, string s2) const
{
  vector<string> strings{s1, s2};
  int numStrings = 2;
  if (numStrings == 1)
    return strings[0];
  if (numStrings == 0)
    return "";
  string prefix;
  int index = 1;

  while (index < 200)
  {
    prefix = strings[0].substr(0, index);
    for (int i = 0; i < numStrings; ++i)
    {
      if (prefix != strings[i].substr(0, index))
      {
        return strings[0].substr(0, index - 1);
      }
    }
    index++;
  }
  return prefix;
}

string ECArrayofStrings ::GetLongestCommonPrefix() const
{
  // your code goes here
  int numStrings = GetNumofStrings();
  vector<string> arrayStrings = vec;
  if (numStrings == 1)
    return arrayStrings[0];
  if (numStrings == 0)
    return "";
  string prefix;
  int index = 1;

  while (index < 200)
  {
    prefix = arrayStrings[0].substr(0, index);
    for (int i = 0; i < numStrings; ++i)
    {
      if (prefix != arrayStrings[i].substr(0, index))
      {
        return arrayStrings[0].substr(0, index - 1);
      }
    }
    index++;
  }
  return prefix;
}

string ECArrayofStrings ::Concatnate() const
{
  // your code goes here
  string out = "";
  for (auto i : vec)
  {
    out += i;
  }
  return out;
}

void ECArrayofStrings::Dump() const
{
  // your code goes here
  for (auto i : vec)
  {
    cout << i << endl;
  }
}
