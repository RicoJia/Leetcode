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
    vector <int> input;
    int expect;

    input = {10,9,2,5,3,7,101,18};
    expect = 4;
    cout<<"ret: "<<s.lengthOfLIS(input)<<" | expect: "<<expect<<endl;

    input = {0,1,0,3,2,3};
    expect = 4;
    cout<<"ret: "<<s.lengthOfLIS(input)<<" | expect: "<<expect<<endl;

    input = {7,7,7,7,7,7,7};
    expect = 1;
    cout<<"ret: "<<s.lengthOfLIS(input)<<" | expect: "<<expect<<endl;


}
