#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

//2022-01-10
//class Solution {
// public:
//     vector<int> n_;
//     int bs(int l, int r){
//         int mid = (l+r)/2;
//         if (l == r) return n_[l];
//         if (l+1 == r) return std::min(n_[l], n_[r]);
//
//         if (n_[mid] > n_[r]){
//             return bs (mid, r);
//         }
//         else{
//             return bs(l, mid);
//         }
//     }
//     int findMin(vector<int>& nums) {
//         n_ = nums;
//         return bs(0, nums.size()-1);
//     }
// };


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

