#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit_after_buy = -1*(1e5), profit_after_sell = 0;
        for(auto& price: prices){
            profit_after_buy = max(profit_after_buy, profit_after_sell - price - fee);
            profit_after_sell = max(profit_after_sell, profit_after_buy + price);
        }
        return profit_after_sell;
    }
};
