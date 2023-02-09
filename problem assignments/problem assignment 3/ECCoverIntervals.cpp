// Given a sorted list, find the smallest number of covering intervals
// For example, if A={1,2,3,5,6,9}, there are three covering intervals [1,3], [5,6] and [9]

int ECSmallestCoverIntervals(const int arrInts[], int szArr)
{
  // arrInts: sorted array of integers; szArr: number of integers in the array
  // Your code here  
  int intervals = 1;
  if (szArr == 0) return 0;
  for (int i = 0; i < szArr - 1; i++) {
    if (arrInts[i + 1] != arrInts[i] + 1) intervals++;
  }
  return intervals;
}

