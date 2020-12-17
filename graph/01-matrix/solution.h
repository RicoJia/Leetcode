#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include <climits>
#include <queue>
using std::queue;

#include <utility>
using std::pair;

class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // Naive thought: left pass, right pass, up pass, downpass. Because we only find the nearest distance, so each pass will make each entry better!!
        // Problem is that the logic is too convoluted, for cells on the edge, and how to update each cell.
        // THIS IS "MIN DISTANCE TO SOMETHING". use: multi-source BFS.
        // so you start from all the 0s, update their neighbors, then search from those neighbors, to update their neighbors.
        // Pay attention to use of queues.
        int row_num = matrix.size(); int cln_num = matrix[0].size();
        vector<vector<int>> ret(row_num, vector<int>(cln_num, INT_MAX));
        queue<pair<int, int> > priority_q;  //you can use std::vec as well.

        // initialize queue with 0 positions
        for(int i = 0; i < row_num; ++i){
            for(int j = 0; j < cln_num; ++j){
                if(matrix[i][j] == 0){
                    ret[i][j] = 0;
                    priority_q.push({i,j});
                }
            }
        }

        // traverse thru the priority queue
        while(!priority_q.empty()){
            auto coord = priority_q.front(); priority_q.pop();
            int dist = ret[coord.first][coord.second];
            // we push the changed cells to the queue for reevaluation.
            auto updateNeighborAndQueue = [&](int r, int c){
                if (0 <= r && r < row_num && 0 <= c && c < cln_num ){
                    int old_val =  ret[r][c];
                    ret[r][c] = std::min(dist+1, ret[r][c]);
                    if(ret[r][c] != old_val){
                        priority_q.push({r, c});
                    }
                }
            };
            updateNeighborAndQueue(coord.first , coord.second - 1);
            updateNeighborAndQueue(coord.first , coord.second + 1);
            updateNeighborAndQueue(coord.first - 1, coord.second );
            updateNeighborAndQueue(coord.first + 1, coord.second );
        }

        return ret;
    }
};