// Solution link: https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/
// CodeStudio link: https://bit.ly/3GItN9P
// Leetcode link: https://leetcode.com/problems/symmetric-tree/
/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool isTwoTreeSymmetric(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;

    if(root1->data == root2->data) {
        return isTwoTreeSymmetric(root1->left, root2->right) && isTwoTreeSymmetric(root2->left, root1->right);
    }
    return false;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return isTwoTreeSymmetric(root, root);   
}