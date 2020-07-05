#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <functional>
using std::function;

class Solution {
public:
    bool exist(vector <vector<char>> &board, string word) {

        unsigned int max_row = board.size(); unsigned int max_cln = board.at(0).size();
        int word_i = 0;

        // need a "visited" table
        vector<vector<bool>> visited_table(max_row, vector<bool>(max_cln, false));

        //DFS lambda function
        std::function<bool (int, int)> can_find_valid_path = [&](int i_r, int i_c) -> bool{

            // case 2: check if the current element is the same as the current word ptr.
            if (word.at(word_i) != board.at(i_r).at(i_c) || visited_table.at(i_r).at(i_c) == true) return false;
            // case 3: check its neighbors
            visited_table.at(i_r).at(i_c) = true;
            ++word_i;
            // case 1: if we have hit the last letter in word, specifically for a single board test case.
            if(word_i == word.length()) return true;

            int r_inc[] = {-1, 0, 1};
            for (int& r_i: r_inc){
                if(0 <= r_i + i_r && r_i + i_r < max_row){
                    vector<int> c_inc = (r_i == 0)? (vector<int>){-1, 1}:(vector<int>){0};
                    for (int& c_i: c_inc){
                        if(0 <= c_i + i_c && c_i + i_c < max_cln){
                            if(can_find_valid_path(r_i + i_r, c_i + i_c))
                                return true;
                        }
                    }
                }
            }
            // case 4: we have not found any valid node. now return false.
            visited_table.at(i_r).at(i_c) = false;
            --word_i;
            return false;
        };

        for (auto row_i = 0; row_i < max_row; ++row_i) {
            for (auto cln_i = 0; cln_i < max_cln; ++cln_i) {
                if(can_find_valid_path(row_i, cln_i) == true)
                    return true;
            }
        }
        return false;
    }
};
