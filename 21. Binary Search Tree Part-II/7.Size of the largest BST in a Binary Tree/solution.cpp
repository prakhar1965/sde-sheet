// CodeStudio link: https://bit.ly/3fn6h5V
// Leetcode link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
/************************************************************

    Following is the Binary Tree node structure
    
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
vector<int> findLargest(TreeNode<int>* root, int &largest) 
{
    if(!root) return {0, INT_MAX, INT_MIN, 1};
    vector<int> left = findLargest(root->left, largest);
    vector<int> right = findLargest(root->right, largest);
    if(   left[3]
        && right[3]
        && root->data > left[2]
        && root->data < right[1]) {
            int sum = left[0]+right[0]+1;
            largest = max(largest, sum);
            int minEle = min(root->data, left[1]);
            int maxEle = max(root->data, right[2]);
            return {sum, minEle, maxEle, 1};
        }
    return {-1, -1, -1, 0};
}
int largestBST(TreeNode<int>* root) 
{
    if(!root) return 0;
    int largest = 0;
    vector<int> ans =  findLargest(root, largest);
    return largest;
}
