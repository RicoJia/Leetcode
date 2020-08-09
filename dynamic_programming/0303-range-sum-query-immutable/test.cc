#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

int main(){
    vector<int> nums;
    NumArray numArray_obj;
    int ret;

    nums = {-2, 0, 3, -5, 2, -1};
    numArray_obj = NumArray(nums);
    ret = numArray_obj.sumRange(0,2);
    cout<<"Solution is 1, and I got: "<<ret<<endl;

    nums = {-2, 0, 3, -5, 2, -1};
    numArray_obj = NumArray(nums);
    ret = numArray_obj.sumRange(2,5);
    cout<<"Solution is -1, and I got: "<<ret<<endl;
}