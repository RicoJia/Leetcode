#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

int main(){
    Solution s;
    int x;
    int ret;
    int sol;

//    for(int x = 0; x<20; ++x){
//        ret = s.mySqrt(x);
//        sol = (int)sqrt(x);
//        cout<<"ret: "<<ret<<" sol: "<<sol<<endl;
//    }

    x = 2147483647;
    ret = s.mySqrt(x);
    sol = (int)sqrt(x);
    cout<<"ret: "<<ret<<" sol: "<<sol<<endl;
}