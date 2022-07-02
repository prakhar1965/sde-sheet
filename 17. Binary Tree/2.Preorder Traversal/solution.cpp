// Solution link: https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
// Leetcode link: https://leetcode.com/problems/binary-tree-preorder-traversal/
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preOrder(TreeNode *root, vector<int> &ans) {
    if(root) {
        ans.push_back(root->data);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
     vector<int> ans;
    preOrder(root, ans);
    return ans;
}