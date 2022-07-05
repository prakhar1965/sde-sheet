// CodeStudio link: https://bit.ly/3Ft26jR
// Leetcode link: https://leetcode.com/problems/search-in-a-binary-search-tree/
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(!root) return false;
    if(root->data == x) return true;
    if(root->data > x)
        return searchInBST(root->left, x);

    return searchInBST(root->right, x);
}