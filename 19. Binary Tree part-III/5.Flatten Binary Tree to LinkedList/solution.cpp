// Solution link: https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
// CodeStudio link: https://bit.ly/3qA9uWt
// Leetcode link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root) return root;
    TreeNode<int> *prev = NULL, *curr = root;
    while(curr) {
        if(curr->left) {
            TreeNode<int> *le = curr->left;
            while(le->right) le = le->right;
            le->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}