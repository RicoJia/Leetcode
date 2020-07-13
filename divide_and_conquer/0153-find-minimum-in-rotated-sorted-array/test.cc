#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

int main(){
    Solution s;
    vector<int> nums;
    int ret, sol;

    nums = {3, 4, 5, 1, 2};
    ret = s.findMin(nums);
    sol = 1;
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    ret = s.findMin(nums);
    sol = 0;
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

    nums = {5,1,2,3,4};
    ret = s.findMin(nums);
    sol = 1;
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;

}
