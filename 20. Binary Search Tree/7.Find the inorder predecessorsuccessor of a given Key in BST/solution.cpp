// CodeStudio link: https://bit.ly/3A0hm6l
// Leetcode link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void findAns(BinaryTreeNode<int>* root, int key, int &prev, pair<int,int> &ans) {
    if(root) {
        findAns(root->left, key, prev, ans);
        if(root->data == key) {
            ans.first = prev;
        }
        if(prev == key) {
            ans.second = root->data;
        }
        prev = root->data;
        findAns(root->right, key, prev, ans);
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans = {-1, -1};
    int prev = -1;

    findAns(root, key, prev, ans);
    return ans;
}
