// Solution link: https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
// CodeStudio link: https://bit.ly/3GtxyQa
// Leetcode link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

void getView(TreeNode<int> *root, vector<int>&ans, int lvl) {
    if(root) {
        if(ans.size() == lvl) ans.push_back(root->data);
        getView(root->left, ans,  lvl+1);
        getView(root->right, ans, lvl+1);
    }
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    
    getView(root, ans, 0);
    return ans;
}