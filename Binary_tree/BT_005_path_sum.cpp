//
// Created by LiuXing on 2019/10/23.
// LeetCode #112

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};


class solution {
public:
    // 凡是遇到跟树有关的题，首先想到用使用递归：divide and conquer
    bool hasPathSum(TreeNode* root, int sum){
        if(!root)
            return false;
        if(root && !root->left && !root->right)
            return sum == root->val;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};