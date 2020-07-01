#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::push_heap;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // build a min heap with the largest k values
        vector<int> smallest_k_vec;
        smallest_k_vec.reserve(k+1);
        smallest_k_vec = {nums.begin(), nums.begin() + k};
        make_heap(smallest_k_vec.begin(), smallest_k_vec.end(), [&](int& a, int& b){ return a > b; });

        for(auto nums_itr = nums.begin() + k; nums_itr < nums.end(); ++nums_itr){
            if(*nums_itr > smallest_k_vec.at(0)){
                smallest_k_vec.push_back(*nums_itr);
                push_heap(smallest_k_vec.begin(), smallest_k_vec.end(), [&](int& a, int& b){ return a > b; });
                pop_heap(smallest_k_vec.begin(), smallest_k_vec.end(), [&](int& a, int& b){ return a > b; });
                smallest_k_vec.pop_back();
            }
        }
        return smallest_k_vec.at(0);
    }
};


