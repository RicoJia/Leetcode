#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<vector<int>>prerequisites;
    int numCourses;

    numCourses = 2;
    prerequisites = {{1,0}};
    cout<<s.canFinish(numCourses, prerequisites)<<endl;

    numCourses = 2;
    prerequisites = {{1,0},{0,1}};
    cout<<s.canFinish(numCourses, prerequisites)<<endl;
    
    numCourses = 4, prerequisites = {{2,0},{1,0},{3,1},{3,2},{1,3}};
    cout<<s.canFinish(numCourses, prerequisites)<<endl;

}