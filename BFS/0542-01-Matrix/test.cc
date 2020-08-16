#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<vector<int>> matrix, ret;
    
    matrix =
    {{0,0,0},
    {0,1,0},
    {1,1,1}};
    ret = s.updateMatrix(matrix); 
    for(auto const& row:ret){
        for (auto const& num: row){
            cout<<num<<" ";
        }
        cout<<endl; 
    }

    matrix =
            {{0,0,0},
             {0,1,0},
             {0,0,0}};
    ret = s.updateMatrix(matrix);
    for(auto const& row:ret){
        for (auto const& num: row){
            cout<<num<<" ";
        }
        cout<<endl;
    }

}
