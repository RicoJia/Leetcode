#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2; i < cost.size(); ++i){
            cost.at(i) += min(cost.at(i-2), cost.at(i-1));
        }

        std::for_each(cost.begin(), cost.end(), [](int i){cout<<i<<" ";});
        cout<<endl;

        int last_i = cost.size()-1;
        if(last_i == 0) return 0;
        return min(cost.at(last_i -1), cost.at(last_i));
    }
};