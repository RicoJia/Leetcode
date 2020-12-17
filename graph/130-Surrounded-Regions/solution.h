#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

#include <unordered_map>
using std::unordered_map;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //Naive thought: use dfs on each border O cell, flip them to something else, then do a whole scan.
        if(board.empty()) return;
        int row_num = board.size();
        int cln_num = board.at(0).size();

        //boarder flips to 'P'
        for(int r = 0; r < row_num; r++){
            dfs(r, 0, board);
            dfs(r, cln_num - 1, board);
        }
        for(int c = 0; c < cln_num; c++){
            dfs(0, c, board);
            dfs(row_num - 1, c, board);
        }

        //flip everything
        for (auto& row: board){
            for(char& c: row){
                if (c == 'O') c = 'X';
                else if (c == 'P') c = 'O';
            }
        }
    }

private:
    void dfs(int r_id, int c_id, vector<vector<char>>& board){
        // return true if it's 'O', else, return false.
        int row_num = board.size();
        int cln_num = board.at(0).size();
        auto flip_cell = [&](int r, int c, char in_token, char out_token){
            if(0 <= r && r < row_num && 0 <= c && c < cln_num){
                if (board.at(r).at(c) == in_token){
                    board.at(r).at(c) = out_token;
                    return true;
                }
            }
            return false;
        };
        bool is_O = flip_cell(r_id, c_id, 'O', 'P');    //P is the temporary token
        if (!is_O) return;
        dfs(r_id, c_id - 1, board);
        dfs(r_id, c_id + 1,board);
        dfs(r_id - 1, c_id, board);
        dfs(r_id + 1, c_id, board);
    }
};
