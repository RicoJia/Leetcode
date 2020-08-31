#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution{
private:
    void dp(vector<vector<int>>& grid, int row_i, int cln_i, int& max){
        // if hitting bottom, or out of the boundary, return, if hitting the first one, return the max(down, right). Corner case: 2x2 matrix
        int row_size = grid.size();
        int cln_size = grid.at(0).size()-1;
        if (row_i == row_size - 1 && cln_i == cln_size - 1 || row_i == row_size || cln_i == cln_size) return;
        int large_num = 1e9;

        // else, keep dp-ing to update the grid.
        dp(grid, row_i + 1, cln_i, max);
        dp(grid, row_i, cln_i + 1, max);
        int& right_child = (cln_i == cln_size -1)?large_num: grid.at(row_i).at(cln_i + 1);
        int& down_child = (row_i == row_size -1 )? large_num:grid.at(row_i + 1).at(cln_i);

        grid[row_i][cln_i] = min({grid[row_i][cln_i], right_child, down_child});
        if(grid[row_i][cln_i] > max ||( row_i != 0 && cln_i != 0)) {
            max = grid[row_i][cln_i];
            cout<<"max: row: "<<row_i<<"cln: "<<cln_i<<endl;}
    }

public:
    int maxOfMinAltitudes(vector <vector<int>> grid) {
        int max = -1;
        dp(grid, 0, 0, max);
        cout << max << endl;
        return max;
    }
};