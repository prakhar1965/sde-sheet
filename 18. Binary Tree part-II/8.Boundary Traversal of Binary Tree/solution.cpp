// Solution link: https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
// CodeStudio link: https://bit.ly/3GxQ6yH
// Leetcode link: https://leetcode.com/problems/boundary-of-binary-tree/#
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
void getBottomBoundary(TreeNode<int>* root, vector<int> &ans) {
    if(!root) return;
    if(!root->left && !root->right) {
         ans.push_back(root->data);
         return;
    }
    getBottomBoundary(root->left, ans);
    getBottomBoundary(root->right, ans);
}
void getLeftBoundary(TreeNode<int>* root, vector<int> &ans) {
    if(!root) return;
    root = root->left;
    while(root) {
        if(root->left || root->right) ans.push_back(root->data);
        if(root->left) root = root->left;
        else  root = root->right;
    }
}
void getRightBoundary(TreeNode<int>* root, vector<int> &ans) {
    if(!root) return;
    vector<int> temp;
    root = root->right;
    while(root) {
        if(root->left || root->right) temp.push_back(root->data);
        if(root->right) root = root->right;
        else  root = root->left;
    }
    int n = temp.size();
    while(--n >= 0) ans.push_back(temp[n]);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    int i = 1;
    if(root->left || root->right) ans.push_back(root->data);
    getLeftBoundary(root, ans);
    getBottomBoundary(root, ans);
    getRightBoundary(root, ans);
    return ans;
}