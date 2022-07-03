// Solution link: https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
// CodeStudio link: https://bit.ly/3I3O1uD
// Leetcode link: https://leetcode.com/problems/diameter-of-binary-tree/
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
int getDiameter(TreeNode<int> *root, int &diameter) {
    if(!root) return 0;

    int maxHeightLeft = getDiameter(root->left, diameter);
    int maxHeightRight = getDiameter(root->right, diameter);

    diameter = max(diameter, maxHeightLeft+maxHeightRight+1);
    return max(maxHeightRight, maxHeightLeft) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{   int diameter = 0;
	getDiameter(root, diameter);
    return diameter-1;
}
