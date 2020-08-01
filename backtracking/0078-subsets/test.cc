#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

#include <algorithm>
using std::for_each;

int main(){
    Solution s;
    vector<int> nums;
    vector<vector<int>> ret;

    nums = {1,2,3};
    ret = s.subsets(nums);
    for_each(ret.begin(), ret.end(), [&](auto& vec){for_each(vec.begin(), vec.end(), [&](int i){cout<<i<<" "; }); cout<<endl;});
    cout<<endl;
}