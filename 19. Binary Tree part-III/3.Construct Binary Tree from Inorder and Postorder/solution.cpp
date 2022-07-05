// CodeStudio link: https://bit.ly/3qrzumM
// Leetcode link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
          { 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
using namespace std;
TreeNode<int> *constructTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int> &hashMap)
{
    if(inStart > inEnd || postStart > postEnd) return NULL;

    int root_data = postorder[postEnd];
    int root_inorder_idx= hashMap[root_data];
    int leftNodes = root_inorder_idx - inStart;

    TreeNode<int> *root = new TreeNode<int>(root_data);

    root->left = constructTree(inorder, postorder, inStart, root_inorder_idx-1, postStart, postStart+leftNodes-1,hashMap);
    root->right = constructTree(inorder, postorder, root_inorder_idx+1, inEnd, postStart+leftNodes, postEnd-1,hashMap);

    return root;

}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    unordered_map<int, int> hashMap;
    int n = inOrder.size();
    if(n == 0) return NULL;
    for(int i=0; i<n; i++) hashMap[inOrder[i]] = i;
    return constructTree(inOrder, postOrder, 0, inOrder.size()-1, 0, postOrder.size()-1, hashMap);
}
