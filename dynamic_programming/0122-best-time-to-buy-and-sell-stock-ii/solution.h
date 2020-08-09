#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
    int profit_with_stock_in_hand = -1*(1e9+5), profit_after_selling_stock = 0;
public:
    int maxProfit(vector<int>& prices) {
        for(auto x: prices){
            profit_with_stock_in_hand = max(profit_with_stock_in_hand, profit_after_selling_stock - x); // you're going to buy this stock since you sold your last one, or not buy anything since you last bought it.
            profit_after_selling_stock = max(profit_after_selling_stock, profit_with_stock_in_hand + x);    // you're going to sell whatever stock you have at this point, compared with not having anything since you sold yours from last time
        }
        return profit_after_selling_stock;
    }
};