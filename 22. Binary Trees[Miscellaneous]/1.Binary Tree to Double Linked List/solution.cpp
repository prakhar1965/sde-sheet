// CodeStudio link: https://bit.ly/3HVnGz0
// Leetcode link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
void inorder(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &prev, BinaryTreeNode<int>* &head) {
    if(!root) return;

    inorder(root->left, prev, head);
    if(!head) {
        head = root;
        prev = root;
    } else {
        prev->right = root;
        root->left = prev;
        prev = root;
    }
    inorder(root->right, prev, head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL, head = NULL;
    inorder(root, prev, head);
    return head;
}