#include "solution.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<vector<int>> input;
    int expected;

    
    input = {{1,1,0},
    {1,1,1},
    {0,1,1}}; 
    expected = 1;
    cout<<"got: "<<s.findCircleNum(input)<<" | expect: "<<expected<<endl;


    input = {{1,1,0},
    {1,1,0},
    {0,0,1}};
    expected = 2; 
    cout<<"got: "<<s.findCircleNum(input)<<" | expect: "<<expected<<endl;

    input = {{1,0,0,1},
             {0,1,1,0},
             {0,1,1,1},
             {1,0,1,1}};
    expected = 1;
    cout<<"got: "<<s.findCircleNum(input)<<" | expect: "<<expected<<endl;

}
