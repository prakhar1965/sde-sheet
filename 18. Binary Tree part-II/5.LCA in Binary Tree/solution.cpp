// Solution link: https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
// CodeStudio link: https://bit.ly/3tqcRko
// Leetcode link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(!root) return -1;
    if(root->data == x) return x;
    if(root->data == y) return y;

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if(left != -1 && right != -1) return root->data;
    if(left != -1) return left;
    return right;
}