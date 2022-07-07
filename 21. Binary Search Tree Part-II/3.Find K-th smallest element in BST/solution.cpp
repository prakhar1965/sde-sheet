// Solution link: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
// CodeStudio link: https://bit.ly/3rf0HrP
// Leetcode link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
void findKth(TreeNode<int> *root, int &ans, int k, int &curr)
{
    if(root) {
        findKth(root->left, ans, k, curr);
        if(curr == k)
            ans = root->data;
        curr++;
        findKth(root->right, ans, k, curr);
    }
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1;
    int curr = 1;
    findKth(root, ans, k, curr);
    return ans;
}