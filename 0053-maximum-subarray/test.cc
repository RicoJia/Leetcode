#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main(){
    Solution s;
    vector<int> nums;
    int ret;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    ret = s.maxSubArray(nums);
    cout<<"ret: "<<ret<<endl;

    nums = {1};
    ret = s.maxSubArray(nums);
    cout<<"ret: "<<ret<<endl;

    nums = {1,2};
    ret = s.maxSubArray(nums);
    cout<<"ret: "<<ret<<endl;

    nums = {-2,1};
    ret = s.maxSubArray(nums);
    cout<<"ret: "<<ret<<endl;
}