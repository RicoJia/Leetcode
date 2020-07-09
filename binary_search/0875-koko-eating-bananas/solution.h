#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cmath>
#include <algorithm>
using std::for_each;

#include <algorithm>
using std::max_element;
using std::min_element;

#include <numeric>
using std::accumulate;

#include <climits>

class Solution {
public:
    int get_total_time(const vector<int>& piles, int H, int K){
        int h = 0;
        for_each(piles.begin(), piles.end(), [&](int num){ h += ceil(((double)num) / K); });
//        cout<<"h: "<<h<<endl<<"-----------"<<endl;
        return h;
    }

    int find_bottom(const vector<int>& piles, int H, int upper, int lower){
        if (upper == lower || lower == upper - 1) return upper;
        int middle = (upper + lower)/2;
//        cout<<"upper: "<<upper<<" lower: "<<lower<<" middle: "<<middle<<endl;
        // if you middle is fast enough, you need to set it to be upper bound for the next one.
        if (get_total_time(piles, H, middle) <= H) return find_bottom(piles, H, middle, lower);
        else return find_bottom(piles, H, upper, middle);
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        if (piles.size() == 1) return ceil(((double) piles.at(0)) / H);
        int upper = *(max_element(piles.begin(), piles.end()));
//        int lower = accumulate(piles.begin(), piles.end(), 0)/H;  //this wouldn't work for a huge numbers, which will cause overflow!
        int lower = accumulate(piles.begin(), piles.end(), 0, [&](int sum, int y){return sum + y/piles.size(); })/H;
        return find_bottom(piles, H, upper, lower);
    }
};


