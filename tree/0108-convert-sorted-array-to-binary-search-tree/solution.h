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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //Naive solution: since the array is sorted in an ascending order: 1. choose the middle element as the head 2. choose the middle elements of the two sub-arrays as the second level heads.
        //Huahua: BST definition: left vals <= root <= right vals. Then, like you said!
        //Corner cases: right inclusive, l>r,
        nums_ = nums;
        return buildTree(0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(int l, int r){
        if(l > r)
            return nullptr;
        // return null if we have reached the end.
        int m = (l + r)/2;
        TreeNode* left_root = buildTree(l, m-1);
        TreeNode* right_root = buildTree(m + 1, r);

        TreeNode* node_ptr = new TreeNode(nums_.at(m), left_root, right_root);
//        node_ptrs_.push_back(node_ptr);
        return node_ptr;
    }
    vector<int> nums_;
};