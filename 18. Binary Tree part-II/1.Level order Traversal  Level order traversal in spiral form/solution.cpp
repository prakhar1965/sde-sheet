// Solution link: https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/
// CodeStudio link: https://bit.ly/3zVtSnX
// Leetcode link: https://leetcode.com/problems/binary-tree-level-order-traversal/
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{   vector<int> ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        ans.push_back(node->val);    
    
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        
    } 
    
    return ans;
}