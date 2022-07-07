// CodeStudio link: https://bit.ly/3nsqdbY
// Leetcode link: https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void findFloor(TreeNode<int>* root, int X, int &ans)
{
    if(!root) return ;
    if(root->val <= X) {
        ans = root->val;
        findFloor(root->right, X, ans);
        return;
    } 
    findFloor(root->left, X, ans);
}
int floorInBST(TreeNode<int> * root, int X)
{
    if(!root) return -1;
    int ans = -1;
    findFloor(root,X, ans);
    return ans;
}