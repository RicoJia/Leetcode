#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// add valid throughout the path.
class Solution {
private:
    void dfs(int row_i, int cln_i, bool& valid, vector<vector<int>>& grid){

        // return when we are outside the boundary. this only happens when we expanded from a boundary node.
        if(row_i < 0 || row_i > grid.size() - 1 ||cln_i < 0 || cln_i > grid.at(0).size()- 1){
            valid = false;
            return;
        }
        if(grid.at(row_i).at(cln_i) == 1) return;      // return when you hit water. Note that you can't hit an explored patch as every complete patch is being explored here!
        grid.at(row_i).at(cln_i) = 1;

        // otherwise, scan thru all four neighbours, if a neighbor returns, we don't care if it hits water or boundary
        // - we want to keep the valid value and mark all the connected islands!!
        dfs(row_i - 1, cln_i, valid, grid);
        dfs(row_i, cln_i - 1, valid, grid);
        dfs(row_i, cln_i  + 1, valid, grid);
        dfs(row_i + 1, cln_i, valid, grid);
        return;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int num_islands = 0;
        for(int row_i = 1; row_i < grid.size(); ++row_i){
            for(int cln_i = 1; cln_i < grid.at(0).size(); ++cln_i){
                if(grid.at(row_i).at(cln_i) == 0){
                    bool valid = true;
                    dfs(row_i, cln_i, valid, grid);
                    num_islands += valid;
                }
            }
        }
        return num_islands;
    }
};