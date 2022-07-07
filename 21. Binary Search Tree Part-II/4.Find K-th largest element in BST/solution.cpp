// Solution link: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
// CodeStudio link: https://bit.ly/31Yjtet
// Leetcode link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void findKth(TreeNode<int> *root, int &ans, int k, int &curr)
{
    if(root) {
        findKth(root->right, ans, k, curr);
        if(curr == k)
            ans = root->data;
        curr++;
        findKth(root->left, ans, k, curr);
    }
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    int curr = 1;
    findKth(root, ans, k, curr);
    return ans;
}
