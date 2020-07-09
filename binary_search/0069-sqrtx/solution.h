#include <iostream>
using std::cout;
using std::endl;

#include <bits/stdc++.h>

#include <climits>

class Solution {
public:
    int getMiddle(int x, int upper, int lower){
        if(lower * lower == x || lower + 1 == upper) return lower;
        else{
            int middle = (upper + lower) / 2;
            while (INT_MAX/middle < middle) --middle;  //for the extreme case where 49152 * 49152 cannot be represented in type 'int'
            // upper bound should never be the real answer.
            if(middle == lower)     //for an extreame large x where middle is initially > INT_MAX/middle.
                return lower;
            cout<<"middle: "<<middle<<"INT_MAX/middle: "<<INT_MAX/middle <<" upper: "<<upper<<endl;
             if (middle * middle <= x)
                return getMiddle(x, upper, middle);
             else
                 return getMiddle(x, middle, lower);
        }
    }
    int mySqrt(int x) {
        if (x == 1|| x == 0) return x;
        int n = 0;
        while(x>>(++n)!=0){}
        return getMiddle(x, 1<<(1+(n-1)/2), 1<<((n-1)/2));
    }
};

