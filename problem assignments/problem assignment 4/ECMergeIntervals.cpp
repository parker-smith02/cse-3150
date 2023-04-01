// Merge overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input
// Your code must run no slower than O(nlogn) where n is the number of intervals

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool pairComp(std::pair<int,int> pair1, std::pair<int,int> pair2) {return (pair1.first < pair2.first);}

void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals)
{
  // your code here...

  //first sort by starting position
  std::vector<std::pair<int,int>> copy = listIntervals;
  std::sort(copy.begin(), copy.end(), pairComp);

  for (auto i : copy) {
    if (!listNonOverlapIntervals.size() || listNonOverlapIntervals.back().second < i.first) {
      listNonOverlapIntervals.push_back(i);
    } else {
      listNonOverlapIntervals.back().second = max(listNonOverlapIntervals.back().second, i.second);
    }
  }

}
