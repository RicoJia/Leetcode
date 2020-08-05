#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {

public: //[0,1,2], 2
    int binary_search(int num, vector<int> i_length_arr, int max_length){
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
};