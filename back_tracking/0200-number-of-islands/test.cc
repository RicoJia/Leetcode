#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

#include <algorithm>
using std::for_each;

int main(){
    Solution s;
    vector<vector<char>> grid;
    int ret;

    grid = {
            vector<char>{'1', '1', '1', '1', '0'},
            vector<char>{'1', '1', '0', '1', '0'},
            vector<char>{'1', '1', '0', '0', '0'},
            vector<char>{'0', '0', '0', '0', '0'}
    };
    ret = s.numIslands(grid);
    cout<<ret<<endl;

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    ret = s.numIslands(grid);
    cout<<ret<<endl;

    grid = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    ret = s.numIslands(grid);
    cout<<ret<<endl;

}