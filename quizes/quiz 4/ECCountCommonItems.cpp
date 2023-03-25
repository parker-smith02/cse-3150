// Created by Y. Wu, Feb 11, 2023
// You are to implement a functionc alled ECCountCommonItems, which takes two parameters: (i) a container X, and (ii) a container Y; this function would count (and return) the number of items that are in BOTH X and Y. 
// For example, X=[1,3,5,8] and Y=[2,3,8,9], then return 2: common items [3,8]
// Note: X and Y can be of different types of containers; but the data types in the two containers are the same and this data type allows equality check (if a==b)
// For this assignment, we will focus on flexibility: supporting different kinds of containers; I will not examine the run-time...

#include <iostream>
using namespace std;

template <class T, class U>
int ECCountCommonItems(T x, U y) {
    int c = 0;
    for (auto i : x) {
        for (auto j : y) {
            if (i == j){
                c++;
            }
        }
    }
    return c;
}



