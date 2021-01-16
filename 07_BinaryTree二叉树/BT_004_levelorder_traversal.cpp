//
// Created by LiuXing on 2019/10/23.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};


class solution{
public:
    // 版本1：直接层次遍历
    vector<int> levelorder1(TreeNode* root){
        vector<int> res;
        queue<TreeNode*> q;
        if(!root)
            return res;
        q.push(root);
        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return res;
    }
public:
    // 版本2：把每一层的结果单独打印出来
    vector<vector<int>> levelorder2(TreeNode* root){
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root)
            return res;
        q.push(root);
        while (!q.empty()){
            vector<int> tmp;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
