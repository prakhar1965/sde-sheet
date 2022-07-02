// Solution link: https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/
// Leetcode link: https://leetcode.com/problems/binary-tree-postorder-traversal/
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
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->data);

    }
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
     vector<int> ans;
    postOrder(root, ans);
    return ans;
}