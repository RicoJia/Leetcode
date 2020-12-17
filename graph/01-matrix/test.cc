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
    vector<vector<int>> matrix =
    {{0,0,0},
    {0,1,0},
    {1,1,1}};

    auto ret = s.updateMatrix(matrix);
    cout<<"I got: "<<endl;
    for (const auto& row: ret){
        for (const int num: row){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;

}
