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
        //Naive solution: for each element, find the largest number in the subsequent array elements. Then, store the difference in an array
        //Solution 2: forward pass: min element up until ith element. Backward pass: max element up until ith the element. len = 0, 1, 2
        //Solution 3: TBD
        if (prices.size() <= 1) return 0;
        vector<int> min_arr(prices.size());
        vector<int> max_arr_backward(prices.size());
        min_arr.at(0) = prices.at(0);
        max_arr_backward.at(prices.size() - 1) = prices.at(prices.size() - 1);
        for (int i = 1; i < prices.size(); ++i){
            min_arr.at(i) = (prices.at(i) < min_arr.at(i-1)) ? prices.at(i) : min_arr.at(i-1);
        }
        int max_prof = max_arr_backward.at(prices.size() - 1) - min_arr.at(prices.size() - 1);
        for (int i = prices.size() - 2; i >=0; --i){
            max_arr_backward.at(i) = (prices.at(i) > max_arr_backward.at(i+1))? prices.at(i) : max_arr_backward.at(i+1);
            int prof =  max_arr_backward.at(i) - min_arr.at(i);
            if (max_prof < prof) max_prof = prof;
        }
        return max_prof;
    }
};