// CodeStudio link: https://bit.ly/3nmKek7
// Leetcode link: https://leetcode.com/problems/validate-binary-search-tree/
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
BinaryTreeNode<int>* findPreDecessor(BinaryTreeNode<int>* root) {
    root = root->left;
    while(root && root->right) root = root->right;
    return root;
}
BinaryTreeNode<int>* findSuccessor(BinaryTreeNode<int>* root) {
    root = root->right;
    while(root && root->left) root = root->left;
    return root;
}

bool validateBST(BinaryTreeNode<int> *root) {
    if(!root) return true;

    bool isLeft = validateBST(root->left);
    if(!isLeft) return false;
    bool isRight = validateBST(root->right);
    if(!isRight) return false;
    
    BinaryTreeNode<int>* pre = findPreDecessor(root);
    BinaryTreeNode<int>* next = findSuccessor(root);
    if(pre && pre->data > root->data) return false;
    if(next && root->data >= next->data) return false;

    return true;
}