// Solution link: https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/
// CodeStudio link: https://bit.ly/3KaM41v
// Leetcode link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    map<int,vector<int>> viewMap;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        viewMap[it.second].push_back(it.first->data);
        TreeNode<int>* node = it.first;

        if(node->left) q.push({node->left, it.second-1});
        if(node->right) q.push({node->right, it.second+1});

    } 
    for(auto it: viewMap) {
        for(int x: it.second)
            ans.push_back(x);
    }
    return ans;
}