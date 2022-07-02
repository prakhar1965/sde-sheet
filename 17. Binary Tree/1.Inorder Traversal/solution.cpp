// Solution link: https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/
// Leetcode link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
void postOrder(TreeNode *root, vector<int> &ans) {
    if(root) {
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}