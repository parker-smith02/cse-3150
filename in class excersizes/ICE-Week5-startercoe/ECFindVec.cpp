#include <vector>
using namespace std;

bool ECFind(const vector<int> &listVecs, int x)
{
  // your code here
  for (auto i : listVecs) {
    if (i == x) {
      return true;
    }
  }
  return false;
}

