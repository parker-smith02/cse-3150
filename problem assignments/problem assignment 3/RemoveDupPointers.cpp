//
//  RemoveDupPointers.cpp
//
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//
void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    // arrayPtrs: STL vector of pointers to strings
    // remove pointers that are pointed to identical strings in the array
    // Your code goes here...
    vector<string> v;
    vector <string *> remove;
    for (int i = 0; i < arrayPtrs.size(); i++)
    {
        if (!count(v.begin(), v.end(), *arrayPtrs[i]))
        {
            v.push_back(*arrayPtrs[i]);
        } else {
            remove.push_back(arrayPtrs[i]);
        }
    }

    for (int j = 0; j < remove.size(); j++) {
        auto itemToRemove = find(arrayPtrs.begin(), arrayPtrs.end(), remove[j]);
        arrayPtrs.erase(itemToRemove);
    }
}
