#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.reserve(std::pow(2, nums.size()));
        ret.push_back(vector<int>());       // empty set
        // append the current number to all prev ones.
        for (int i = 0; i < nums.size(); ++i){
            for(auto vec: ret){
                vec.push_back(nums.at(i));
                ret.push_back(vec);
            }
        }
        return ret;
    }
};