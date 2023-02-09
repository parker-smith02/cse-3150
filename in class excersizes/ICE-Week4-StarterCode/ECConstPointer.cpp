#include <iostream>

using namespace std;

int ECSumArray(const int *listNums, int size)
{
  // You need to loop through the array using pointer. How to define this pointer? 
  int res = 0;
  int *ptr = const_cast<int *>(listNums);
  for (int i = 0; i < size; i++) {
    res += *ptr;
    ptr++;
  }
  return res;
}

int main()
{
  int array[] = {1,2,3,5};
  ECSumArray(array, 4);
  return 0;
}
