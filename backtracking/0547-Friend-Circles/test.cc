#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<vector<int>> M;
    int ret;

    M = {{1,1,0},
    {1,1,0},
    {0,0,1}};
    ret = s.findCircleNum(M);
    cout<<"Solution is 2, I got : "<<ret<<endl;

    M = {{1,0,0,1},
         {0,1,1,0},
         {0,1,1,1},
         {1,0,1,1}};
    ret = s.findCircleNum(M);
    cout<<"Solution is 1, I got : "<<ret<<endl;
}
