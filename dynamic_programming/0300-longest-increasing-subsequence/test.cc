#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Solution s;
    //binary search test cases [0,1], 0; [0,1], 1; [0,1,2], 1
    vector<int> nums;
    int ret;

//    cout<<"solution is: "<<0<<" ,and I got: "<<s.binary_search(0, {1}, 1)<<endl;
//    cout<<"solution is: "<<0<<" ,and I got: "<<s.binary_search(1, {1}, 1)<<endl;
//    cout<<"solution is: "<<1<<" ,and I got: "<<s.binary_search(2, {1}, 1)<<endl;
//
//    cout<<"solution is: "<<0<<" ,and I got: "<<s.binary_search(0, {0,1,2}, 3)<<endl;
//    cout<<"solution is: "<<1<<" ,and I got: "<<s.binary_search(1, {0,1,2}, 3)<<endl;
//    cout<<"solution is: "<<2<<" ,and I got: "<<s.binary_search(2, {0,1,2}, 3)<<endl;
//    cout<<"solution is: "<<3<<" ,and I got: "<<s.binary_search(3, {0,1,2}, 3)<<endl;
//
//    cout<<"solution is: "<<3<<" ,and I got: "<<s.binary_search(3, {0,1,2,4}, 4)<<endl;
//    cout<<"solution is: "<<3<<" ,and I got: "<<s.binary_search(4, {0,1,2,4}, 4)<<endl;
//
//    cout<<"solution is: "<<1<<" ,and I got: "<<s.binary_search(1, {0,1,4}, 3)<<endl;
//    cout<<"solution is: "<<2<<" ,and I got: "<<s.binary_search(2, {0,1,4}, 3)<<endl;
//    cout<<"solution is: "<<3<<" ,and I got: "<<s.binary_search(5, {0,1,4}, 3)<<endl;
//    cout<<"solution is: "<<1<<" ,and I got: "<<s.binary_search(3, {2,5}, 2)<<endl;

    nums = {10,9,2,5,3,7,101,18};
    ret = s.lengthOfLIS(nums);
    cout<<"solution is: "<<4<<" ,and I got: "<<ret<<endl;
}