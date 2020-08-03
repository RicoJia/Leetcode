#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<int> nums;
    int ret;
//
//    nums = {3,1,3,4,2};
//    ret = s.findDuplicate(nums);
//    cout<<ret<<endl;
//
//    nums = {1,3,4,2,2};
//    ret = s.findDuplicate(nums);
//    cout<<ret<<endl;

    nums = {1,4,4,2,4};
    ret = s.findDuplicate(nums);
    cout<<ret<<endl;
}