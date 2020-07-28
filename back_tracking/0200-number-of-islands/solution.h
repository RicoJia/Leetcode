#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;


class Solution {
private:
    void DFS_count(vector <vector<char>> &grid, int row_i, int cln_i) {
        if(0 <= row_i && row_i < grid.size() && 0 <= cln_i && cln_i < grid.at(0).size() && grid.at(row_i).at(cln_i) == '1'){
            grid.at(row_i).at(cln_i) = '0';
            for (int r = -1; r < 2; ++r) {
                for (int c = -1; c < 2; ++c) {
                    if(r+c==-1 || r+c==1){
                        DFS_count(grid, row_i + r, cln_i + c);
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int row_i = 0; row_i < grid.size(); ++row_i){
            for(int cln_i = 0; cln_i < grid.at(0).size(); ++cln_i){
                if(grid.at(row_i).at(cln_i) == '1'){
                    DFS_count(grid, row_i, cln_i);
                    ++num;
                    cout<<"row_i, cln_i: "<<row_i<<" "<<cln_i<<endl;
                }
            }
        }
        return num;
    }
};