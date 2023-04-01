#include <iostream>
#include <algorithm>
using namespace std;

static bool IsSmaller(int x, int y) {
  return x < y;
}
static bool IsLarger(int x, int y) {
  return x > y;
}

static bool OddOrder(int x, int y) {
  bool fxOdd = (x % 2) == 1;
  bool fyOdd = ( y % 2) == 1;
  if (fxOdd && !fyOdd) {
    return true;
  }
  if (!fxOdd && fyOdd) {
    return false;
  }
  return x < y;
}

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, bool (*pf)(int, int))
{
  // your code here
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (pf(listNumbers[j], listNumbers[i])) {
        std::swap(listNumbers[i], listNumbers[j]);
      }
    }
  }
}

int main()
{
  int arr[] = {1,3,2,4};
  ECSortFP(arr, 4, OddOrder);

  // print it out
  for(int i=0; i<4; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

