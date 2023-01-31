#include <iostream>
using namespace std;

void ECRemoveSpace(int nums[], int len, int val)
{
  // your code here
  int left = 0, right = len - 1;
  while (left < right) {
    if (nums[left] == val) {
      nums[left] = nums[right];
      nums[right] = '_';
      right--;
    } else {
      left++;
    }
  }
}


