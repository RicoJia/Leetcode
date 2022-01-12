#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <climits>

// 2022-01-06 - DP, error: signed integer overflow, 31/55 passed
class Solution {
public:
   
    void preprocess(vector<vector<int>>& g){
        for (auto& row: g)
            for (auto& cell: row){
                if (cell == 1)
                    cell = -1; 
            }
        g[g.size()-1][g[0].size()-1] = 1;
    }
    
    int neighbor_val(int r, int c, vector<vector<int>>& obstacleGrid){
        int R = obstacleGrid.size(); 
        int C = obstacleGrid[0].size(); 
        if (r == R || c == C || obstacleGrid[r][c] == -1) return 0; 
        else return obstacleGrid[r][c]; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Obstacle Check
        int R = obstacleGrid.size(); 
        int C = obstacleGrid[0].size(); 
        if (obstacleGrid[R-1][C-1] == 1 || obstacleGrid[0][0] == 1) return 0; 

        preprocess(obstacleGrid); 
        
        for (int r = R-1; r >= 0; --r){
            for(int c = C-1; c >= 0; --c){
                if (r == R-1 && c == C-1)
                    continue; 
                if (obstacleGrid[r][c] == -1)
                    continue; 
                obstacleGrid[r][c] = neighbor_val(r+1, c, obstacleGrid) + neighbor_val(r, c+1, obstacleGrid);
            }
        }
        
        for (auto r: obstacleGrid){
            for(auto c: r)
                cout<<c<<" ";
            cout<<endl;  
        }
        
        return obstacleGrid[0][0]; 
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row_num = obstacleGrid.size(), cln_num = obstacleGrid.at(0).size();
        if(obstacleGrid.at(row_num-1).at(cln_num-1) == 1) return 0;
        obstacleGrid.at(row_num-1).at(cln_num-1) = 1;
        int max_layer_num = (row_num > cln_num)? row_num: cln_num;
        for (int layer_i = 1; layer_i < max_layer_num; ++layer_i){
            // fill the left column, from bottom to the second cell from the top.
            if(layer_i < cln_num){
                for(int r = 0; r < ((layer_i > row_num)?row_num: layer_i); ++r){            //the r bound was wrong
                    auto &current_cell = obstacleGrid.at(row_num - 1 - r).at(cln_num - layer_i - 1);
                    int right_val = obstacleGrid.at(row_num - 1 - r).at(cln_num - layer_i); //you don't need (layer > 1), since you are not covering the right most cells.
                    int down_val = (r > 0)?obstacleGrid.at(row_num - r).at(cln_num - layer_i - 1):0;       //TODO
                    long long k = (long)right_val + (long)down_val;
                    if(k>INT_MAX) k = k%1000000007;
                    current_cell = (current_cell == 1)?0:k;
                }
            }
            // fill the top row, from right to the second cell from the left.
            if(layer_i < row_num){
                for(int c = 0; c < ((layer_i > cln_num)?cln_num:layer_i); ++c){
                    auto& current_cell = obstacleGrid.at(row_num - 1 - layer_i).at(cln_num - 1 - c);
                    int right_val = (c > 0)?obstacleGrid.at(row_num - 1 - layer_i).at(cln_num - c) : 0;
                    int down_val = obstacleGrid.at(row_num - layer_i).at(cln_num - 1 -c);
                    long long k = (long)right_val + (long)down_val;
                    if(k>INT_MAX) k = k%1000000007;
                    current_cell = (current_cell == 1)?0:k;
                }
            }
            // the top left
            if(layer_i < row_num && layer_i < cln_num){
                auto& current_cell = obstacleGrid.at(row_num - 1 - layer_i).at(cln_num - 1- layer_i);
                int right_val = obstacleGrid.at(row_num - 1 - layer_i).at(cln_num - layer_i);
                int down_val = obstacleGrid.at(row_num - layer_i).at(cln_num - 1 - layer_i);
                long long k = (long)right_val + (long)down_val;
                if(k>INT_MAX) k = k%1000000007;
                current_cell = (current_cell == 1)?0:k;
            }
        }
        return obstacleGrid.at(0).at(0);
    }
};

//#include <climits>
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        obstacleGrid[0][0]=(obstacleGrid[0][0]+1)%2;
//        for(int i=1;i<m;i++)
//            if(obstacleGrid[i][0]==1 || obstacleGrid[i-1][0]==0){
//                obstacleGrid[i][0]=0;
//            }else
//                obstacleGrid[i][0]=1;
//        for(int i=1;i<n;i++)
//            if(obstacleGrid[0][i]==1 || obstacleGrid[0][i-1]==0){
//                obstacleGrid[0][i]=0;
//            }else
//                obstacleGrid[0][i]=1;
//        for(int i=1;i<m;i++)
//            for(int j=1;j<n;j++){
//                if(obstacleGrid[i][j]==1)
//                    obstacleGrid[i][j]=0;
//                else{
//                    long long k = ((long)obstacleGrid[i-1][j]+(long)obstacleGrid[i][j-1]);
//                    if(k>=INT_MAX){
//                        obstacleGrid[i][j]=k%1000000007; //this simple modification can be done to reuse same int array
//                    }else{
//                        obstacleGrid[i][j]=k;
//                    }
//                }
//            }
//
//        return obstacleGrid[m-1][n-1];
//    }
//
//};

/*huahua solution*/
//#include <climits>
//
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int n = obstacleGrid.size();
//        if (n == 0) return 0;
//        int m = obstacleGrid[0].size();
//
//        // f[i][j] = paths(i, j)
//        // INT_MIN -> not solved yet, solution unknown
//        f_ = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MIN));
//
//        int ret = paths(m, n, obstacleGrid);
//        obstacleGrid = f_;
//        return ret;
//    }
//private:
//    vector<vector<int>> f_;
//
//    int paths(int x, int y, const vector<vector<int>>& o) {
//        // Out of bound, return 0.
//        if (x <= 0 || y <= 0) return 0;
//
//        // Reaching the starting point.
//        // Note, there might be an obstacle here as well.
//        if (x == 1 && y == 1) return 1 - o[0][0];
//
//        // Already solved, return the answer.
//        if (f_[y][x] != INT_MIN) return f_[y][x];
//
//        // There is an obstacle on current block, no path
//        if (o[y - 1][x - 1] == 1) {
//            f_[y][x] = 0;
//        } else {
//            // Recursively find paths.
//            f_[y][x] = paths(x - 1, y, o) + paths(x, y - 1, o);
//        }
//
//        // Return the memorized answer.
//        return f_[y][x];
//    }
//};
