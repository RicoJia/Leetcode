#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

int main(){
    Solution s;
    vector<int> nums;
    int target, ret, sol;

    nums = {1,3,5,6};
    target = 5;
    sol = 2;
    ret = s.searchInsert(nums, target);
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

    nums = {1,3,5,6};
    target = 2;
    sol = 1;
    ret = s.searchInsert(nums, target);
    cout << "ret: " << ret << " sol: " << sol << endl;

    nums = {1,3,5,6};
    target = 7;
    sol = 4;
    ret = s.searchInsert(nums, target);
    cout << "ret: " << ret << " sol: " << sol << endl;

    nums = {1,3,5,6};
    target = 0;
    sol = 0;
    ret = s.searchInsert(nums, target);
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

    nums = {1};
    target = 0;
    sol = 0;
    ret = s.searchInsert(nums, target);
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

    nums = {1};
    target = 1;
    sol = 0;
    ret = s.searchInsert(nums, target);
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

    nums = {1};
    target = 2;
    sol = 1;
    ret = s.searchInsert(nums, target);
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;
}