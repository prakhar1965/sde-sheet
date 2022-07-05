// CodeStudio link: https://bit.ly/3Fr7GTQ
// Leetcode link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--) {
        if(s.size() == 1) {
            ans[i] = s.top();
        }
        else {
            while(s.size() != 1 && arr[i] >= arr[s.top()]) {
                s.pop();
            }
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}
TreeNode<int> *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &nextGreaterArray)
{
    if(preStart > preEnd) return NULL;

    int nextGreatIdx = nextGreaterArray[preStart];
     
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    
    
    if(nextGreatIdx <= preEnd && nextGreatIdx != -1) 
    {
        root->left = constructTree( preorder, preStart+1, nextGreatIdx-1,nextGreaterArray);
        root->right = constructTree(preorder, nextGreatIdx, preEnd,nextGreaterArray);
    }
    else 
    {
        root->left = constructTree( preorder, preStart+1, preEnd,nextGreaterArray);
    }

    return root;

}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int n = preOrder.size();
    if(n == 0) return NULL;
    vector<int> nextGreaterArr = nextGreater(preOrder, preOrder.size());
    return constructTree(preOrder,0, preOrder.size()-1, nextGreaterArr);
}

