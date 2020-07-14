#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

//class Solution {
//public:
//    int helper(const vector<int> &nums, int start, int end, int target) {
//        if (nums.at(end)< target) return end + 1;   //possible: nums[end] < target
//        if (nums.at(start) >= target) return start;
//        if (start == end) return start + 1;
//        if (start + 1 == end) return end;   //possible: nums[end] >= target, nums[start] < target;
//
//        int mid =(start + end) / 2;  //if start and end are neighbours, and nums[start] == target here will be returned,
//        return (nums.at(mid) == target) ? mid : (nums.at(mid) < target) ? helper(nums, mid, end, target) : helper(nums,
//                                                                                                                  start,
//                                                                                                                  mid,
//                                                                                                                  target);
//    }
//    int searchInsert(vector<int>& nums, int target) {
//        //Assume nums not empty
//        int start = 0, end = nums.size()-1;
//        return helper(nums, start, end, target);
//    }
//};

//faster solution:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        if(nums.at(start) >= target) return start;
        if(nums.at(end) < target ) return end + 1;
        while(start + 1 != end){
            int mid = (start + end)/2;
            if(nums.at(mid) == target) return  mid;
            else if (nums.at(mid)  < target) start = mid;
            else end = mid;
        }
        return (nums.at(start) < target)? end:start;
    }
};