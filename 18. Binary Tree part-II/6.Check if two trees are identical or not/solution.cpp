// Solution link: https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
// CodeStudio link: https://bit.ly/3GuQYnE
// Leetcode link: https://leetcode.com/problems/same-tree/
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;

    if(root1->data != root2->data) return false;
    bool isLeft =  identicalTrees(root1->left, root2->left);
    bool isRight = identicalTrees(root1->right, root2->right);

    return isLeft && isRight;
}