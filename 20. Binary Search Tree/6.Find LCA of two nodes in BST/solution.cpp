// CodeStudio link: https://bit.ly/3qqoaXM
// Leetcode link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root) return NULL;
    if(root->data == P->data) return P;
    if(root->data == Q->data) return Q;
    if(root->data > P->data && root->data < Q->data) return root;
    if(root->data > Q->data && root->data < P->data) return root;

    if(root->data > P->data) return LCAinaBST(root->left, P, Q);
    return LCAinaBST(root->right, P, Q);
}
