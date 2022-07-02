// Solution link: https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/
// CodeStudio link: https://bit.ly/3rm014d
// Leetcode link: https://leetcode.com/problems/maximum-width-of-binary-tree/
#include<bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{   if(!root) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    int maxWidth = 0, curr_width = 0;
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        if(!node) {
            maxWidth = max(curr_width, maxWidth);
            curr_width = 0;
            if(!q.empty()) q.push(NULL);
        } else {
            curr_width++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    } 
    
    return maxWidth;
}