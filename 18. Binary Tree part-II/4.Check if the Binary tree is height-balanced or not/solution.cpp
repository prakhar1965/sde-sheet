// Solution link: https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree/
// CodeStudio link: https://bit.ly/3fqsvnA
// Leetcode link: https://leetcode.com/problems/balanced-binary-tree/
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
pair<bool, int> checkBalance(BinaryTreeNode<int>* root) {
    if(!root) retutn {true, 0};

    pair<bool, int> left = checkBalance(root->left);
    pair<bool, int> right = checkBalance(root->right);

    bool isBalanced = left.first && right.first && (abs(left.second - right.second) <= 1);

    return {isBalanced, max(left.second, right.sceond) + 1};
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return checkBalance(root).first;
}