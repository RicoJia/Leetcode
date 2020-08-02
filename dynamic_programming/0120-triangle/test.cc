#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<vector<int>> triangle;
    int ret;

    triangle = {
    {2},
    {3,4},
    {6,5,7},
    {4,1,8,3}
    }; 
    ret = s.minimumTotal(triangle);
    cout<<ret<<endl;
}