// Solution link: https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal/
// CodeStudio link: https://bit.ly/3fqOif3
// Leetcode link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
TreeNode<int> *constructTree(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int,int> &hashMap)
{
    if(inStart > inEnd || preStart > preEnd) return NULL;

    int root_data = preorder[preStart];
    int root_inorder_idx= hashMap[root_data];
    int leftNodes = root_inorder_idx - inStart;

    TreeNode<int> *root = new TreeNode<int>(root_data);

    root->left = constructTree(inorder, preorder, inStart, root_inorder_idx-1, preStart+1, preStart+leftNodes,hashMap);
    root->right = constructTree(inorder, preorder, root_inorder_idx+1, inEnd, preStart+leftNodes+1, preEnd,hashMap);

    return root;

}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int, int> hashMap;
    int n = inorder.size();
    if(n == 0) return NULL;
    for(int i=0; i<n; i++) hashMap[inorder[i]] = i;
    return constructTree(inorder, preorder, 0, inorder.size()-1, 0, preorder.size()-1, hashMap);
}