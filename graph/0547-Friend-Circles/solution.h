#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

class Solution{
public:
    int findCircleNum(vector<vector<int>>& M) {
        //Naive solution: for every element, first list its first degree connections. Then, explore every single first degree connection: flip the sign in the status_board.
        // O(n2)
        // If the sign is already flipped, move on. else, Build its first degree connections and flip
        // better solution:
        if (M.empty()) return 0;
        M_ = M;
        status_board_ = vector<bool> (M.size(), false); //true for explored 
        circle_num_ = 0;
        for (int i = 0; i < status_board_.size(); ++i) {
            if(status_board_.at(i) == false){
                cout<<"index: "<<i<<endl;
                dfs(i);
                ++circle_num_;
            }
        }
        return circle_num_;
    }

private: 
    void dfs(int index){
        vector <bool> status;
        status.reserve(status_board_.size()); 
        status_board_[index] = true;
        // This is the tricky part: next_index cannot be index, as there might be unexplored friend before index, like 0 -> 5 -> 1, which means 1 cannot be ignored.
        for (int next_index = 0; next_index < status_board_.size(); ++next_index){
            if (M_[index][next_index] == 1 && status_board_[next_index]== false ){ dfs(next_index); }
        }
    }

    vector<vector<int>>M_;
    vector<bool> status_board_;
    int circle_num_;
};