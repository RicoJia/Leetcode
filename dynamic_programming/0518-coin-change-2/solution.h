#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
private:
    int num_sol_; 
    int dp(int amount, vector<int>& coins, int current_index, int current_sum){
        if(current_sum == amount) {
//            cout<<"success!"<<endl;
            ++num_sol_;
            return 1;
        }
        if(current_sum > amount) {
//            cout<<"failed!"<<endl;
            return -1;
        }
        else{
            for(int ii = current_index; ii<coins.size(); ++ii){
//                cout<<"current_sum: "<<current_sum<<" current_index: "<<current_index<<" to add: "<<ii<<endl;
                int ret = dp(amount, coins, ii, current_sum + coins.at(ii));
                if(ret == -1) continue;
            }
            return 1;   //not sure
        }
    }

public:
    int change(int amount, vector<int>& coins) {
        num_sol_ = 0;
        dp(amount, coins, 0,0);
        return num_sol_;
    }
};

