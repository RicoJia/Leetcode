#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<int> v {-2,1,-3,4,-1,2,1,-5,4};
    auto sol = s.maxMiddleArray_(v, 0,0,0);
    cout<<"got: "<<sol<<", expect: "<<6<<endl;

    v= {-2147483647};
    sol = s.maxMiddleArray_(v,0,0,0);
    cout<<"got: "<<sol<<", expect: "<<-2147483647<<endl;
}
