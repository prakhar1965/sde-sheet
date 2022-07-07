// CodeStudio link: https://bit.ly/3FsH5FC
// Leetcode link: https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTiterator
{
    stack<TreeNode<int>*> S;
    BSTiterator(TreeNode<int> *root)
    {
        S.push(root);
        while(root->left) {
            S.push(root->left);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode<int>* curr = S.top();
        S.pop();
        TreeNode<int> * curr_right = curr->right;
        while(curr_right) {
            S.push(curr_right);
            curr_right = curr_right->left;
        }

        return curr->data;
    }

    bool hasNext()
    {
        return !S.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/