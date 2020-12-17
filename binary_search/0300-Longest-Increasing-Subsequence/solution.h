#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

#include <unordered_map>
using std::unordered_map;
#include <map>
using std::map;

#include <iterator>
using std::advance;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums) {
        // Naive thought: build an ordered map of (val, id), in increasing order. Then, start from the rightmost value of the map.
        // Then, have a vector that keeps track of the largest length from each subsequence. update from the right to the left.
        // map wouldn't work for there are repeating terms. So that means we cannot use map.
        if (nums.empty()) {
            return 0;
        }
        // build ordered lookup
        vector<vector<int>> lookup; lookup.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            lookup.push_back({nums.at(i), i});
        }
        std::sort(lookup.begin(), lookup.end(), [](const auto& vec1, const auto& vec2){return vec1.at(0) < vec2.at(0); });

        vector<int> max_lens(nums.size(), 1);
        int max_len = 1;

        //access ith element in the map. beg -> second
        // iterate thru all subsequent elements in the map, update max_sub_len if its val is greater too.
        // need to use std::advance on map iterators? can't do < for iterators and must do != instead?
        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                // if this new element is behind than the current element.
                if (lookup.at(j).at(1) > lookup.at(i).at(1)  && lookup.at(j).at(0) > lookup.at(i).at(0)) {
                    int new_len = max_lens.at(j) + 1;
                    if (max_lens.at(i) < new_len) max_lens.at(i) = new_len;
                    if (max_lens.at(i) > max_len) max_len = max_lens.at(i);
                }
            }
        }

        return max_len;
    }
};

/* METHOD 2 - Binary-search
 *     int binary_search(int num, vector<int> i_length_arr, int max_length){
        int left = 0, right = max_length - 1;
        if (num <=i_length_arr.at(0)) return 0;
        if (num > i_length_arr.at(max_length - 1)) return max_length;
        //max_length is the size of the array.here we start from max_length so size = 1 will be considered. the number will be
        while(left <= right){           //left+1 == right is possible. [0,1]. left == right is possible, [0,1] searching for 1. But this might have an impact on mid.
            int mid = (left + right)/2;
            if(mid + 1 == max_length || num > i_length_arr.at(mid) && num <= i_length_arr.at(mid + 1))      // since left < right, we know mid < right.[0,1,2], right = 3.
                return mid+1;
            else{
                if(num > i_length_arr.at(mid + 1)) left = mid + 1;
                else right = mid;   //num < i_length_arr(mid)
            }
        }
        return left;
    }

    //    nums = {10,9,2,5,3,7,101,18}; =>
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return  0;
        vector<int> i_length_arr = vector<int>(nums.size(), -1);
        i_length_arr.at(0) = nums.at(0);
        int max_length = 1;
        for (int i = 1; i < nums.size(); ++i){
            int index_in_arr = binary_search(nums.at(i), i_length_arr, max_length);
            if (index_in_arr + 1> max_length) ++max_length;
            i_length_arr.at(index_in_arr) = nums.at(i);
        }
        return max_length;
    }
 * */
