// CodeStudio link: https://bit.ly/3nqSnnQ
// Leetcode link: https://practice.geeksforgeeks.org/problems/mirror-tree/1
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

bool invert(TreeNode<int> *root, TreeNode<int> *leaf) {
    if(!root) return false;
    if(root == leaf) return true;

    bool isLeft = invert(root->left, leaf);
    if(isLeft) {
        TreeNode<int> *curr = root->left;
        root->left = NULL;
        curr->left = root;
        return true;
    }
    bool isRight = invert(root->right, leaf);
    if(isRight) {
        TreeNode<int> *curr = root->left;
        root->right->left = root;
        root->right = curr;
        return true;
    }
    return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    invert(root, leaf);
	return leaf;
}
