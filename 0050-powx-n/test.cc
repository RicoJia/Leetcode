#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Solution s;
    double ret;
//
    ret = s.myPow(2.00000, 10);
    cout<<"ret: "<<ret<<" Sol: "<<1024<<endl;


    ret = s.myPow(2.00000, -2);
    cout<<"ret: "<<ret<<" Sol: "<<0.25000<<endl;

    ret = s.myPow(2.10, 3);
    cout<<"ret: "<<ret<<" Sol: "<<9.26100<<endl;

    ret = s.myPow(0.00001, 2147483647);
    cout<<"ret: "<<ret<<" Sol: "<<0<<endl;

    ret = s.myPow(-1, 2147483647);
    cout<<"ret: "<<ret<<" Sol: "<<-1<<endl;

    ret = s.myPow(2, -2147483648);
    cout<<"ret: "<<ret<<" Sol: "<<0<<endl;

}