#include <iostream>
using std::cout;
using std::endl;


#include <vector>
using std::vector;

#include <climits>

#include <algorithm>
using std::max;
using std::max_element;

// Method 2
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
///*        - When there's one letter, you return the letter; */
//        if (nums.size() == 1)
//            return nums.at(0);
//
//        /*                  - When the vector monotonically decreases, you return the max among all of them.*/
//        int max_ele = *(max_element(nums.begin(), nums.end()));
//        if (max_ele <= 0)
//            return max_ele;
//
//        int min_sum = nums.at(0);
//        int largest_diff = nums.at(0);
//        int sum = nums.at(0);
//        for (auto i = 1; i < nums.size(); ++i){
//            sum += nums.at(i);
//            if(sum < min_sum )
//                min_sum = sum;
//            else{
///*               When there are ups and downs, you do not just record the historical min and max cdf, because max might occur after min.
//                        Instead, you always update the differencerence. Therefore, you keep a record of the historical min cdf,
//                1. if the current cdf <  historical min  cdf, update the latter
//                2. else, see if (current_cdf - historical min) > largest_diff; if yes, update.
//                3. There is an exception, where the largest difference is the sum of all numbers. This cannot be covered by the previous two cases,
//                because you need historical_min to be 0, which may not be the case.
//                4. There is also another exception: nums = [-2, 1]. **BUT this can be covered by the first case** - have historical_cdf start at nums.at(0),
//                        then current_cdf - historical cdf will reflect individual elements.*/
//
//                        largest_diff = max({sum, largest_diff, (sum - min_sum)});
//            }
//        }
//        return largest_diff;
//    }
//};


// Method 3
//TODO

class Solution {
public:

    // for the middle cross term.
    int maxMiddleArray_(vector<int> &nums, int l, int r, int m) {
        // left elements, including m
        int left_max = INT_MIN, right_max = INT_MIN;
        int sum = 0;
        for (int i = m; i >= l; --i) {
            sum += nums.at(i);
            left_max = (sum > left_max)? sum: left_max;
        }

        // right elements, not including m.
        sum = 0;
        for (int i = m+1; i <= r; ++i){
            sum += nums.at(i);
            right_max = (sum > right_max)? sum: right_max;
        }
        return left_max + right_max;        //see what happens with nums = [2,1]. Answer: this is fine, even tho it returns -1, it will be comapred with -2 and 1, the left max and right max, and 1 will win.
        // also, it fits the cross term definition perfectly.
    }

    // for the left and right cases
    int maxArray_(vector<int>& nums, int l, int r, int m){
        if(l == r) return nums.at(l);
        int new_m = (l+r)/2;
        return max({maxArray_(nums, l, new_m, (l+new_m)/2),
                maxArray_(nums, new_m+1, r, (new_m+1+r)/2),
                maxMiddleArray_(nums, l, r, m)});
    }

    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums.at(0);
        return maxArray_(nums, 0, nums.size()-1, (nums.size()-1)/2);
    }
};
