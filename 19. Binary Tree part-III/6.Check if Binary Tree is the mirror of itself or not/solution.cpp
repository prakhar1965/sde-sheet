// CodeStudio link: https://bit.ly/3nqSnnQ
// Leetcode link: https://practice.geeksforgeeks.org/problems/mirror-tree/1
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
bool populateParent(TreeNode<int> *root, TreeNode<int>*leaf,stack<TreeNode<int>*> &s) {
    s.push(root);
    if(!root->left && !root->right) {
        if(root->data == leaf->data)
            return true;
        else {
            s.pop();
            return false;
        }
    }
    if(root->left) {
        if(populateParent(root->left,leaf,s))
            return true;
    }
    if(root->right) {
        if(populateParent(root->right,leaf,s))
            return true;
    }
    s.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
   
    stack<TreeNode<int>*> st;
    populateParent(root,leaf,st);
    TreeNode<int>* newRoot = st.top() ,*par = newRoot;
    st.pop();
    while(!st.empty()) {
        TreeNode<int>* curr = st.top();
        st.pop();
        if(curr->left == par){
            curr->left = NULL;
            par->left = curr;
        } else {
            curr->right = curr->left;
            curr->left = NULL;
            par->left = curr;
        }
        par = curr;
    }
    return newRoot;
}