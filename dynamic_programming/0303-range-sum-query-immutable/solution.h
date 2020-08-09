#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;

class NumArray {
private:
    vector<int> nums_sum_;
public:
    NumArray(){}

    NumArray(vector<int>& nums): nums_sum_(nums) {
        for (int i = 1; i < nums_sum_.size(); ++i){
            nums_sum_.at(i) = nums_sum_.at(i-1) + nums_sum_.at(i);
        }
    }

    int sumRange(int i, int j) {
        return (i == 0)?nums_sum_.at(j):nums_sum_.at(j) - nums_sum_.at(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */