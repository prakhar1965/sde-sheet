// CodeStudio link: https://bit.ly/33b9enW
// Leetcode link: https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos


void findCielData(BinaryTreeNode<int>* root, int X, int &ans)
{
    if(!root) return ;
    if(root->data >= X) {
        ans = root->data;
        findCielData(root->left, X, ans);
        return;
    } 
    findCielData(root->right, X, ans);
}
int findCeil(BinaryTreeNode<int> * root, int X)
{
    if(!root) return -1;
    int ans = -1;
    findCielData(root,X, ans);
    return ans;
}