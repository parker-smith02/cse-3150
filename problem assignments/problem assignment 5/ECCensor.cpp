// Created by Y. Wu, Jan 31, 2023
// You are given an input containter (of any STL set/vec/etc) of certain type (e.g., int, string, etc), a container of forbidden items (which may be any STL container type, and so may not be sorted), and a new censored value (of the same type). You are to output (STL container of the same type) the sorted list of items from the input such that this list contains all the items from the input, and any value appearing in the forbidden list is converted to the censored value.
// For example, suppose the input: [1 -1 2, 5, 2], forbidden list [-1], censored value = 0, then the output is: [0, 1, 2, 2, 5]

// Now define the function ECCensor ...
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename ContainerIn, typename ContainerF, typename Val, typename ContainerO>
void ECCensor(ContainerIn &in, ContainerF &forbidden, Val converted, ContainerO &out)
{

    vector<typename ContainerIn::value_type> vec(forbidden.begin(), forbidden.end());
    sort(vec.begin(), vec.end());

    for (auto i : in)
    {

        bool check = binary_search(vec.begin(), vec.end(), i);
        if (check)
            out.insert(upper_bound(out.begin(), out.end(), converted), converted);
        else
            out.insert(upper_bound(out.begin(), out.end(), i), i);
    }
}
