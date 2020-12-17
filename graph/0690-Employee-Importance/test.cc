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
    vector<Employee*> input;
    int id ;
    int expect;

    expect = 3;
    id = 2;
    input = {new Employee(1,2,{2}), new Employee(2,3,{})};
    cout<<"ret: "<<s.getImportance(input, id)<<" | expect: "<<expect<<endl;

    expect = 5;
    id = 2;
    input = {new Employee(1,2,{2}), new Employee(2,3,{})};
    cout<<"ret: "<<s.getImportance(input, id)<<" | expect: "<<expect<<endl;

}
