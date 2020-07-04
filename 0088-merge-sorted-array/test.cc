#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main(){

    vector<int>v1;
    vector<int>v2;
    int m, n;

    Solution s;
    v1={1,2,3,0,0,0};
    v2 = {2,5,6};
    m = 3; n = 3;
    s.merge(v1, m, v2, n);
    for (auto i: v1){
        cout<<i<<" ";
    }
    cout<<"---------------"<<endl;

}