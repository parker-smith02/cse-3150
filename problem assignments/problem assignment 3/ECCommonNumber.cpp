// Given two arrays of integers, return true (and also store the smallest integer that is in both arrays). Return false if no such integer exists 
// For example, suppose A1={1, 5, 3, 1} and A2={3, 7, 2}. Then ECCommonNumber(A1, 4, A2, 3, val) would return true (and val would be 3 after function call returns). Here, A1 is the first array, 4 is the size of the first array, A2 is the second array and 3 is the size of the second array. 
// Note: you must implement your algorithm as efficiently as possible
// Also, you need to define the function yourself: how are you going to take
// Tip: don't reinvent the wheel; try to use C++ standard library functions

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool ECCommonNumber(int A[], int szA, int B[], int szB, int &val) 
{
  // your code here...
  vector<int> newA(A, A + szA);
  vector<int> newB(B, B + szB);

  sort(newA.begin(), newA.end());
  sort(newB.begin(), newB.end());
  for (int i : newA) {
    if (binary_search(newB.begin(), newB.end(), i)) {
      val = i;
      return true;
    }
  }
  return false;


}



