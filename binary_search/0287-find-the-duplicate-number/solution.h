#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
public:
    //[1,4,4,2,4]
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;

        while (left <= right){      // this makes sure left == right is still evaluated
            int mid = (left + right)/2;
            if(left == right) return left;      //for when left == right, this happens when left = mid + 1 = right.
            int count_l = 0, count_mid = 0;
            for (int i = 0; i < nums.size(); ++i){
                if(nums.at(i) < mid) ++count_l;
                else if(nums.at(i) == mid) ++count_mid;
            }
            if(count_mid >= 2) return mid;      // because in the question, you may have more than 2 duplicates.
            else {
                if(count_l <= mid -1) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
