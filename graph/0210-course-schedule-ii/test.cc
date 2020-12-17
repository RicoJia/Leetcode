#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<vector<int>> prerequisites;
    int numCourses;
    vector<int> ret; 
    
//    prerequisites = {{1,0},{2,0},{3,1},{3,2}};//
//    numCourses = 4;
//    ret = s.findOrder(numCourses, prerequisites);   // {0,1,2,3} or {0,2,1,3}
//    for(int i: ret){cout<<i<<" ";}
//    cout<<endl;
//    //{0:  {1, 2}, 1: {3}, 2: {3}, 3:{}}

    prerequisites = {{0,1}};
    numCourses = 2;
    ret = s.findOrder(numCourses, prerequisites);   // {0,1,2,3} or {0,2,1,3}
    for(int i: ret){cout<<i<<" ";}
    cout<<endl;
    cout<<"expect: "<<"1 0"<<endl;


    prerequisites = {{0,2},{1,2},{2,0}};
    numCourses = 3;
    ret = s.findOrder(numCourses, prerequisites);   // {0,1,2,3} or {0,2,1,3}
    for(int i: ret){cout<<i<<" ";}
    cout<<endl;
    cout<<"expect: "<<""<<endl;
//    {0:  {2}, 1: {}, 2: {0,1}}

}
