// Solution link: https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/
// CodeStudio link: https://bit.ly/3rlXpTX

/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
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


************************************************************/
void traverse(BinaryTreeNode<int> *root, vector<vector<int>> &ans) {
    if(root) {
        ans[1].push_back(root->data);
        traverse(root->left, ans);
        ans[0].push_back(root->data);
        traverse(root->right, ans);
        ans[2].push_back(root->data);
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    traverse(root, ans);
    return ans;
}