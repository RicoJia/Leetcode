#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

class Solution{
public:
    int maxMiddleArray_(vector<int> &nums, int l, int r, int m) {
        //Naive solution: o(n^2), for each element, add all of them, find the max in the array
        // DP solution: O(n): for every element, check if you get a larger value by + the previous sum. If so, add. If not, break here and say up until this point, the largest sum is myself.
        //Solution 3: divide and conquer -
        vector<int> dp = nums;
        int max = nums.at(0);

        for (int i = 0; i < nums.size(); ++i){
            if(dp[i-1] + nums.at(i) > nums.at(i)) dp[i] = dp[i-1] + nums.at(i);
            max = std::max(max, dp[i]);
        }
        return max;
    }
};