// CodeStudio link: https://bit.ly/3qr5I1t
// Leetcode link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
TreeNode<int>* bst(vector<int> &arr, int start, int end)
{   
    if(start > end) return NULL;
    int mid = (start+end+1)/2;

    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = bst(arr, start, mid-1);
    root->right = bst(arr, mid+1, end);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return bst(arr, 0,n-1);
}