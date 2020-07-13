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
    vector<int> sol, ret;
    int target;


    nums = {5,7,7,8,8,10};
    target = 6;
    sol = {-1, -1};
    ret = s.searchRange(nums, target);
    cout<<"---------------"<<endl<<"return: ";
    for_each(ret.begin(), ret.end(), [](int &num) { cout << num << " "; });
    cout<<"solution: ";
    for_each(sol.begin(), sol.end(), [](int& num){cout<<num<<" "; });
    cout<<endl;
//
//    nums = {5,7,7,8,8,10};
//    target = 8;
//    sol = {3,4};
//    ret = s.searchRange(nums, target);
//    cout<<"---------------"<<endl<<"return: ";
//    for_each(ret.begin(), ret.end(), [](int &num) { cout << num << " "; });
//    cout<<"solution: ";
//    for_each(sol.begin(), sol.end(), [](int& num){cout<<num<<" "; });
//    cout<<endl;
//
//    nums = {8,8,10};
//    target = 8;
//    sol = {0,1};
//    ret = s.searchRange(nums, target);
//    cout<<"---------------"<<endl<<"return: ";
//    for_each(ret.begin(), ret.end(), [](int &num) { cout << num << " "; });
//    cout<<"solution: ";
//    for_each(sol.begin(), sol.end(), [](int& num){cout<<num<<" "; });
//    cout<<endl;
//
//    nums = {8};
//    target = 8;
//    sol = {0,0};
//    ret = s.searchRange(nums, target);
//    cout<<"---------------"<<endl<<"return: ";
//    for_each(ret.begin(), ret.end(), [](int &num) { cout << num << " "; });
//    cout<<"solution: ";
//    for_each(sol.begin(), sol.end(), [](int& num){cout<<num<<" "; });
//    cout<<endl;

    nums = {8};
    target = 6;
    sol = {-1,-1};
    ret = s.searchRange(nums, target);
    cout<<"---------------"<<endl<<"return: ";
    for_each(ret.begin(), ret.end(), [](int &num) { cout << num << " "; });
    cout<<"solution: ";
    for_each(sol.begin(), sol.end(), [](int& num){cout<<num<<" "; });
    cout<<endl;

}