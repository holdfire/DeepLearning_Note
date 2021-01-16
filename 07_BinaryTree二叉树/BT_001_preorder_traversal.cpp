//
// Created by LiuXing on 2019/10/23.
// LeetCode #144
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};


class solution{
public:
    // recursive version
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        recursion(root, res);
        return res;
    }

private:
    void recursion(TreeNode *root, vector<int>& res){
        if (!root)
            return;
        res.push_back(root->val);
        recursion(root->left, res);
        recursion(root->right, res);
        return;
    }


    // non-recursive version
public:
    vector<int> preorderTraversal2(TreeNode *root){
        vector<int> res;
        stack<TreeNode*> s;
        if(!root)
            return res;
        s.push(root);
        while(!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
        }
        return res;
    }
};


