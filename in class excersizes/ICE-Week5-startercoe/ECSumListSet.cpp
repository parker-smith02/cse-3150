#include <set>
#include <vector>
#include <iostream>
using namespace std;

int ECSumList(const set<int> &listNums)
{
  // your code goes here ...
  int res = 0;

  for (auto i : listNums) {
    res += i;
  }

  return res;
}

