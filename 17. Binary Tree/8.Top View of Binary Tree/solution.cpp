// Solution link: https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree/
// CodeStudio link: https://bit.ly/3trqFLq
// Leetcode link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
using namespace std;


vector<int> getTopView(TreeNode<int> * root) {
    if(!root) return {};
    vector<int> ans;
    map<int,int> viewMap;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        if(viewMap.find(it.second) == viewMap.end())
            viewMap[it.second] = it.first->val;
        TreeNode<int> *node = it.first;

        if(node->left) q.push({node->left, it.second-1});
        if(node->right) q.push({node->right, it.second+1});

    } 
    for(auto it: viewMap) 
        ans.push_back(it.second);
    return ans;
}
