// Solution link: https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
// CodeStudio link: https://bit.ly/3GrS3g7
// Leetcode link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/*************************************************************

    Following is the Binary Tree node structure

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
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{   vector<int> ans;
    if(!root) return ans;
    deque<BinaryTreeNode<int>*> Q1;
    Q1.push_back(root);
    int direction = 1;
    while(!Q1.empty()) {
        int size = Q1.size();
        for(int i=0; i<size; i++) {
            BinaryTreeNode<int>* curr;
            if(direction == 1) {
                 curr = Q1.front();
                 Q1.pop_front();
            } else {
                 curr = Q1.back();
                 Q1.pop_back();
            }
            
            ans.push_back(curr->data);
            if(direction == 1) {
                if(curr->left) Q1.push_back(curr->left);
                if(curr->right) Q1.push_back(curr->right);
            } else {
                if(curr->right) Q1.push_front(curr->right);
                if(curr->left) Q1.push_front(curr->left);
            }
            
        }
        direction ^= 1;
    }
    return ans;
}
