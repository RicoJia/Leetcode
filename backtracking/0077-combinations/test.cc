#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

#include <algorithm>
using std::for_each;

int main(){
    Solution s;
    int n, k;
    vector <vector<int>> ret;

    n = 4, k = 2;
    ret = s.combine(n, k);
    for_each(ret.begin(), ret.end(), [](auto& vec){for_each(vec.begin(), vec.end(), [](int& n){cout<<n<<" "; }); cout<<endl;});
}