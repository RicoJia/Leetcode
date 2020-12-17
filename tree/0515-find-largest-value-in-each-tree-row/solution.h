#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        //Naive solution: 1. make an array of INT_MIN (you might need to dynamically allocate memory, which is slow.). 2. have a dfs. which passes in the last level, and increment.
        // Compare with INT_MIN.
        largest_vals_.reserve(10000);
        dfs(root, 0);
        return largest_vals_;
    }
    void dfs(TreeNode* root, int height){
        if(!root) return;
        if(largest_vals_.size() == height){
            largest_vals_.push_back(root->val);
        }
        else{
            largest_vals_.at(height) = std::max(largest_vals_.at(height), root->val);
        }
        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }

    vector<int> largest_vals_;
};