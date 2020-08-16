#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 
using std::vector;
using std::string;
int main(){
    Solution s;
    vector<string> strs;
    int m, n, ret;

    strs={"10","0","1"};
    m = 1, n = 1;
    ret = s.findMaxForm(strs, m,n);
    cout<<"solution is 2, and I got: "<< ret<<endl;

    strs={"10","0001","111001","1","0"};
    m = 5, n = 3;
    ret = s.findMaxForm(strs, m,n);
    cout<<"solution is 4, and I got: "<< ret<<endl;
}
