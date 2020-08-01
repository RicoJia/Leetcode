#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<int> nums;
    int ret;

    nums = {4,5,6,7,0,1,2};
    ret = s.findMin(nums);
    cout<<ret<<endl;

    nums = {3,4,5,1,2 };  //1
    ret = s.findMin(nums);
    cout<<ret<<endl;

    nums = {4,5,6,7,0,1,2};   //0
    ret = s.findMin(nums); 
    cout<<ret<<endl;    
}