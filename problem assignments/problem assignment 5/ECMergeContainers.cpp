// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc
// Make your code short: at most 10 lines of code (LOC)

// now defiine ECMergeContainers ...

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T1, typename T2>

void ECMergeContainers(T1 &x, T2 &out)
{
    for (auto i : x)
    {
        out.insert(out.begin(), i.begin(), i.end());
    }
    sort(out.begin(), out.end());
}
