#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
private:
    void dfs(int row_i, int cln_i, vector<vector<int>>& M){
        if (row_i < 0 || row_i >= M.size() || cln_i < 0 || cln_i >= M.at(0).size()){
            return;
        }
        // hit a stranger
        if (M.at(row_i).at(cln_i) == 0) return;
        M.at(row_i).at(cln_i) = 0;
        // same cln
        for (int next_row_i = 0; next_row_i < M.size(); ++next_row_i) {
            if(next_row_i == row_i) continue;
            dfs(next_row_i, cln_i, M);
        }
        for(int next_cln_i = 0; next_cln_i < M.at(0).size(); next_cln_i++){
            if(next_cln_i == cln_i) continue;
            dfs(row_i, next_cln_i, M);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int num = 0;
        for(int row_i = 0; row_i < M.size(); ++row_i){
            for(int cln_i = 0; cln_i < M.at(0).size(); ++cln_i){
                if(M.at(row_i).at(cln_i) == 1){
                    ++num;
                    //mark all friends to 0.
                    dfs(row_i, cln_i, M);
                }
            }
        }
        return num;
    }
};

