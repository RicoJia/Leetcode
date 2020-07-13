#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
    int helperGetMin(const vector<int>& nums, int start, int end){
        if (start + 1 == end || start == end) return min(nums.at(start), nums.at(end));   //it's likely that start == end, such as one single element sub-array
        int mid = (start + end)/2;
        int ret = min(helperGetMin(nums, start, mid), helperGetMin(nums, mid+1, end));
        return ret;
    }
public:
    int findMin(vector<int>& nums) {
        return helperGetMin(nums, 0, nums.size()-1);
    }
};

