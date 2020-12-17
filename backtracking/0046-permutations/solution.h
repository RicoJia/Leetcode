#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //Naive solution: 1. make a vec of vec, 10^5. each vector 2. start from 1, append the new digit to any position. 3. copy the new set of vecs over. But this requires a lot of copying and erasing.
        //The best way is have a vector, reserved for the full length, and do push backs.
        //This should be done in a DFS way
        if(nums.size() == 0) return {nums};     //return the array itself
        vector<vector<int>> ret;
        ret.push_back({});
//        ret.push_back({});
        for (int element_num = 1; element_num <= nums.size(); ++element_num){
            dfs(element_num, ret, nums);
        }
        return ret;
    }

    void dfs(int element_num, vector <vector<int>> &ret, const vector<int> &nums) {
        int ret_size = ret.size();
        for (int curr_vec_index = 0; curr_vec_index < ret_size; ++curr_vec_index) {
            for (int insert_index = 0; insert_index < element_num; ++insert_index) {
                vector<int> curr_vec = ret.at(curr_vec_index);
                curr_vec.insert(curr_vec.begin() + insert_index, nums.at(element_num - 1));
                ret.push_back(curr_vec);
            }
        }
        ret.erase(ret.begin(), ret.begin() + ret_size);    //remove the old vectors.
    }
};