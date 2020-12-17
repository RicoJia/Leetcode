#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<vector<int>> times;
    int N, K;
    times = {{2,1,1},{2,3,1},{3,4,1}};
    N = 4;
    K = 2;
    cout<<s.networkDelayTime(times, N, K);

//    times = {{1,2,1},{2,1,3}};
//    N = 2;
//    K = 2;
//    cout<<s.networkDelayTime(times, N, K);

}
