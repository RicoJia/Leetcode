#include "solution.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    int n;
    int headID;
    vector<int> manager;
    vector<int> informTime;
    int ret;

    n = 7;
    headID = 6;
    manager = {1,2,3,4,5,6,-1};
    informTime = {0,6,5,4,3,2,1};
    ret = 21;
    cout<<"got: "<< s.numOfMinutes(n, headID, manager, informTime)<<" | ret: "<< ret<<endl;


    n = 6;
    headID = 2;
    manager = {2,2,-1,2,2,2};
    informTime = {0,0,1,0,0,0};
    ret = 1;
    cout<<"got: "<< s.numOfMinutes(n, headID, manager, informTime)<<" | ret: "<< ret<<endl;

    n = 1;
    headID = 0;
    manager = {-1};
    informTime = {0};
    ret = 0;
    cout<<"got: "<< s.numOfMinutes(n, headID, manager, informTime)<<" | ret: "<< ret<<endl;

    n = 15;
    headID = 0;
    manager = {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6};
    informTime = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    ret = 3;
    cout<<"got: "<< s.numOfMinutes(n, headID, manager, informTime)<<" | ret: "<< ret<<endl;

    n = 4;
    headID = 2;
    manager = {3,3,-1,2};
    informTime = {0,0,162,914};
    ret = 1076;
    cout<<"got: "<< s.numOfMinutes(n, headID, manager, informTime)<<" | ret: "<< ret<<endl;
}
