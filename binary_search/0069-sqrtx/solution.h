#include <iostream>
using std::cout;
using std::endl;

#include <bits/stdc++.h>

#include <climits>

class Solution {
    int binarySearch(int l, int r) {
        if (r - l <= 1)
            return l;
        int mid = l + (r - l) / 2;
        int quo = x_ / mid;
        if (mid > quo) return binarySearch(l, mid);
        else if (mid < quo) return binarySearch(mid, r);
        else return mid;
    }
public:
    // Naive solution: use binary search: if r - l <= 0, return l.
    int mySqrt(int x) {
        x_ = x;
        return binarySearch(0, x);
    }
    int x_;
};

