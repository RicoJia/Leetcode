#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;

///*Slow implementation*/
//class Solution {
//private:
//    int num_sol_;
//    int dp(int amount, vector<int>& coins, int current_index, int current_sum){
//        if(current_sum == amount) {
////            cout<<"success!"<<endl;
//            ++num_sol_;
//            return 1;
//        }
//        if(current_sum > amount) {
////            cout<<"failed!"<<endl;
//            return -1;
//        }
//        else{
//            for(int ii = current_index; ii<coins.size(); ++ii){
////                cout<<"current_sum: "<<current_sum<<" current_index: "<<current_index<<" to add: "<<ii<<endl;
//                int ret = dp(amount, coins, ii, current_sum + coins.at(ii));
//                if(ret == -1) continue;
//            }
//            return 1;   //not sure
//        }
//    }
//
//public:
//    int change(int amount, vector<int>& coins) {
//        num_sol_ = 0;
//        dp(amount, coins, 0,0);
//        return num_sol_;
//    }
//};



class Solution {
private:
    vector<vector<int>> coin_table_;
    /*
      1   2   3   4   5
[1]   1   1   1   1   1
[1,2] 1   1+1 1+1 1+2  1+2
     */
    void fillCoinTable(int amount, vector<int>& coins){
        for(int a = 1; a < amount + 1; ++a){
            coin_table_.at(0).at(a-1) = (a % coins.at(0) == 0)?1:0;        // fill the first row
        }

        for(int row_i = 1; row_i < coins.size(); ++row_i){
            for(int a = 1; a < amount + 1; ++a){
                int diff = a - coins.at(row_i);
                coin_table_.at(row_i).at(a-1) = coin_table_.at(row_i - 1).at(a-1)  + ((diff < 0)? 0 : ((diff == 0)?1: coin_table_.at(row_i).at(diff - 1)));
            }
        }

//        for_each(coin_table_.begin(), coin_table_.end(), [](vector<int>& vec){
//            for_each(vec.begin(), vec.end(), [](int num){cout<<num<<" ";});
//            cout<<endl;
//        });
    }

public:
    int change(int amount, vector<int>& coins)
    {
        if (amout == 0) return 1;
        if (coins.size() == 0) return 0;
        coin_table_ = vector<vector<int>>(coins.size(), vector<int>(amount));   //the input does not contain 0.
        fillCoinTable(amount, coins);
        return coin_table_.at(coin_table_.size()-1).at(amount - 1);
    }
};



