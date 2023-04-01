#include <vector>
#include <iostream>
using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums)
{
  // your code goes here ...
  int sum = 0;
  for (auto i : listNums) {
    sum += i;
  }
  return sum;
}

