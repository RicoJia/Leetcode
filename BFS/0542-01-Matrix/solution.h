#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <cmath>
using std::abs;

#include <algorithm>
using std::min;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // construct the distance and q matrices
        vector<vector<int>> distance (matrix.size(), vector<int>(matrix.at(0).size(), 1e5));
        queue<vector<int>> q;
        for(int row_i = 0; row_i < matrix.size(); ++row_i){
            for(int col_i = 0; col_i < matrix.at(0).size(); ++col_i){
                if(matrix.at(row_i).at(col_i) == 0){
                    distance.at(row_i).at(col_i) = 0;
                    q.push({row_i, col_i});
                }
            }
        }

        while(!q.empty()){
            auto coords = q.front();
            q.pop();
            for(int i = -1; i < 2; ++i){
                for (int j = -1; j < 2; ++j) {
                    // a valid 4-connectivity neighbor
                    if (abs(i + j) == 1 &&
                        0 <= coords[0] + i && coords[0] + i < matrix.size() &&
                        0 <= coords[1] + j && coords[1] + j < matrix.at(0).size()) {
                            int temp = distance[coords[0] + i][coords[1] + j];
                            distance[coords[0] + i][coords[1] + j] = min(temp, distance[coords[0]][coords[1]] + 1);
                            if(temp != distance[coords[0] + i][coords[1] + j]) q.push({coords[0] + i, coords[1] + j});
                    }
                }
            }
        }
        return distance;
    }
};
