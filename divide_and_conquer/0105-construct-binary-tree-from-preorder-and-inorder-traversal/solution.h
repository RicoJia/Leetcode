#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::find;

#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* buildSubTree(const vector<int>& preorder, const vector<int>& inorder,
            std::vector<int>::const_iterator pre_order_beg,
                           std::vector<int>::const_iterator pre_order_end,
                           std::vector<int>::const_iterator in_order_beg,
                           std::vector<int>::const_iterator in_order_end){
        if (pre_order_beg == pre_order_end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(*pre_order_beg);
//        cout<<"root: "<<root -> val<<endl;

        if (pre_order_beg + 1 == pre_order_end){
            return root;
        }

        auto root_itr_in_order = find(in_order_beg, in_order_end, root->val);



        root->left = buildSubTree(preorder, inorder, pre_order_beg + 1,
                                      pre_order_beg + (root_itr_in_order - in_order_beg) + 1, in_order_beg, root_itr_in_order);
        root->right = buildSubTree(preorder, inorder, pre_order_beg + (root_itr_in_order - in_order_beg) + 1,
                                   pre_order_end, root_itr_in_order + 1, in_order_end);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = buildSubTree(preorder, inorder, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        return root;
    }
};