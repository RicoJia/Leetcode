#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
#include <vector>
using std::vector;

class Solution {
public:
    // This is Huahua solution, dfs for combination. We push vectors into the solution array, once the size is full. Else, call dfs to append to the array
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ret;
        vector<int> curr;
        //[0,1,2]: the sequence to add is {}; [0]. [1], [2]; [0,1], [1,2], [0,1,2]
        for(int element_num = 0; element_num <= nums.size(); ++element_num){
            dfs(0, element_num, nums, curr, ret);
        }
//        cout<<"------------"<<endl;
        return ret;
    }
    void dfs(int start, int element_num, const vector<int>& nums, vector<int>& curr, vector <vector<int>>& ret){
        if (curr.size() == element_num){
            ret.push_back(curr);
            return;
        }
        for (int next_start = start; next_start < nums.size(); ++next_start){
            curr.push_back(nums.at(next_start));
            dfs(next_start+1, element_num, nums, curr, ret);
            curr.pop_back();        // because we are using reference, so we need to pop what we just added from curr for the next iteration
        }
    }
};