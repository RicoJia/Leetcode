#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row_num = triangle.size();
        for (int r = row_num - 2; r >= 0; --r){
            for (int n_i = 0; n_i < triangle.at(r).size(); ++n_i){
                triangle.at(r).at(n_i) += min(triangle.at(r + 1).at(n_i), triangle.at(r+1).at(n_i+1));
            }
        }
        return triangle.at(0).at(0);
    }
};

