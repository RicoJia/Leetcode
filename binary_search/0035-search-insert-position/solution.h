#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Lessons Learned
//     - use the same name as input arg. like target_
//     - Use their submissions can help debug faster. 
// class Solution {
// public:
//     vector<int> n_;
//     int t_;
//     int bs(int l, int r){
//         int mid = (l+r)/2;
//         // cout<<mid<<" "<<l<<" "<<r<<endl;
//         // might have l + 1 = r, mid = l in the last run, and here r = l-1 
//         if (l >= r){
//             if (n_[l] >=t_) return l;
//             else return l+1; 
//         }
//         
//         if (n_[mid] == t_) return mid; 
//         else if (n_[mid] < t_){
//             return bs(mid+1, r);
//         }
//         else{
//             return bs(l, mid-1);
//         }
//     }
//     int searchInsert(vector<int>& nums, int target) {
//         n_ = nums;
//         t_ = target; 
//         return bs(0, n_.size()-1);
//     }
// };

class Solution {
public:
   int helper(const vector<int> &nums, int start, int end, int target) {
       if (nums.at(end)< target) return end + 1;   //possible: nums[end] < target
       if (nums.at(start) >= target) return start;
       if (start == end) return start + 1;
       if (start + 1 == end) return end;   //possible: nums[end] >= target, nums[start] < target;

       int mid =(start + end) / 2;  //if start and end are neighbours, and nums[start] == target here will be returned,
       return (nums.at(mid) == target) ? mid : (nums.at(mid) < target) ? helper(nums, mid, end, target) : helper(nums, start, mid, target);
   }
   int searchInsert(vector<int>& nums, int target) {
       //Assume nums not empty
       int start = 0, end = nums.size()-1;
       return helper(nums, start, end, target);
   }
};

//faster solution:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        if(nums.at(start) >= target) return start;
        if(nums.at(end) < target ) return end + 1;
        while(start + 1 != end){
            int mid = (start + end)/2;
            if(nums.at(mid) == target) return mid;
            else if (nums.at(mid) < target) start = mid;
            else end = mid;
        }
        return (nums.at(start) < target)? end:start;
    }
};
