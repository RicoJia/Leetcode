#include <iostream>
using std::cout;
using std::endl;


#include <vector>
using std::vector;

#include <algorithm>
using std::max;

//[7,1,5,3,6,4]
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //[7]?
        //max_profit <= 0?
        int max_profit = 0;
        if(prices.size() == 0) return max_profit;
        int prev = prices.at(prices.size() - 1);
        prices.at(prices.size() - 1) = 0;
        for (int ii = prices.size() - 2; ii >= 0; --ii) {
            int temp = prices.at(ii);
            prices.at(ii) = max(prev - prices.at(ii), prices.at(ii + 1) + prev - prices.at(ii));         //max prize from previous = prev_price+prev
            prev = temp;
            if (prices.at(ii) > max_profit) max_profit = prices.at(ii);
        }
        return max_profit;
    }
};