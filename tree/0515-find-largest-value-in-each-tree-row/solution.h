#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Method2 2022-02-08
class Solution {
public:
    vector<int> vec_; 
    TreeNode* build_tree(int l, int r){
        if (l > r) return nullptr; 
        int mid = (l+r)/2; 
        TreeNode* root = new TreeNode(vec_.at(mid));
        if (l == r) return root; 
        root -> left = build_tree(l, mid - 1); 
        root -> right = build_tree(mid+1, r); 
        return root; 
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        for (auto beg = head; beg != nullptr; beg = beg->next){
            vec_.emplace_back(beg->val); 
        }
        return build_tree(0, vec_.size()-1); 
    }
};
// Method-1 11-28-2020
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Naive solution: convert this list into an array, then convert this array into a binary search tree: find mid, the two mids.
        // How to traverse a binary search tree: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solution/
        // Better (more convoluted idea): 1. use a pointer, traverse thru the list, know the length. Then, dfs on the first half : 1. examine l <= r + 1, if so, make node and a ptr, and return
        // the ptr. 2. find mid,  3. call dfs on left partition, connect the returned ptr to the left 4. call dfs on the right partition.
        start_ = head;
        auto trav = head;
        int len = 0;
        while (trav != nullptr){
            ++len;
            trav = trav -> next;
        }

        return dfs(0, len - 1);
    }

private:
    TreeNode* dfs(int l, int r){
        if(l > r){      // why we prefer to return null -  because you don't have to deal with single leaves separately.
            return nullptr;
        }

        int mid = (l + r)/2;
        auto left = dfs(l, mid - 1);
        auto root = new TreeNode(start_ -> val);
        root -> left = left;
        start_ = start_ -> next;
        root -> right = dfs(mid + 1, r);
        return root;
    }
    ListNode* start_;
};
