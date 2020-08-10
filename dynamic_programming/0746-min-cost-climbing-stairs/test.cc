#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<int> cost;
    int ret;

    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    ret = s.minCostClimbingStairs(cost);
    cout<<"Solution is 6, I got: "<<ret<<endl;

    cost = {10, 15, 20};
    ret = s.minCostClimbingStairs(cost);
    cout<<"Solution is 15, I got: "<<ret<<endl;
}