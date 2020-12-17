#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(){
    Solution s;
    string str;
    s = "3+2*2";

    cout<<"ret: "<<s.calculate(s)<<"answer: "<<7<<endl;


}
