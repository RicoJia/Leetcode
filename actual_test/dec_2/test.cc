#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    Solution s;
    string str;
    int expect;
    int ret;

    str = "nenigehnieighgh";
    ret = s.countHorses(str);
    expect = 2;
    cout<<"ret: "<<ret<<" | expect: "<<expect<<endl;

}
