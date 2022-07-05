// Solution link: https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree/
// CodeStudio link: https://bit.ly/3rkQUR4
// Leetcode link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include<bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the Tree node structure
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int findPath(TreeNode<int> *root, long long &ans)
{
    if(!root) return -1;

    long long leftMax = findPath(root->left, ans);
    long long rightMax = findPath(root->right, ans);

    if(leftMax == -1 && rightMax == -1) return root->val;;
    if(leftMax == -1) return root->val + rightMax;
    if(rightMax == -1) return root->val + leftMax;


    ans = max(ans, (root->val + leftMax + rightMax));
    return root->val + max(rightMax, leftMax);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long ans = -1;
    findPath(root, ans);
    return ans;
}