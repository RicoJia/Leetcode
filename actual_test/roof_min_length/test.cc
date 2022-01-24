#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    Solution s;
    vector<int> cars; 
    int k; 
    int expect; 

    cars = {12,6,5,2}; 
    k = 3;
    auto ret = s.sln(cars, k);
    expect = 5; 
    cout<<"ret: "<<ret<<" | expect: "<<expect<<endl;

}
