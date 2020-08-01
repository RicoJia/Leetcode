#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
private:
    // find min in [start, end)
    int find_min_dfs(const vector<int>& nums, int start, int end){
        if (start + 1 == end) return nums.at(start); // the single element case. Since we're sticking to [start, end), we never have start == end
        if (start + 2 == end) return (nums.at(start) <= nums.at(end - 1))?  nums.at(start): nums.at(end-1);   // when nums.at(start) == nums.at(end), we return start.
        int mid = (start + end)/2;
        int left_min = find_min_dfs(nums, start, mid), right_min = find_min_dfs(nums, mid, end);
        return (left_min <= right_min)? left_min: right_min;
    }
public:
    int findMin(vector<int>& nums) {
        return find_min_dfs(nums, 0, nums.size());
    }
};

