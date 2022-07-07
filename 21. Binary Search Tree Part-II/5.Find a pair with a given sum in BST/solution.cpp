// CodeStudio link: https://bit.ly/3FvDAOO
// Leetcode link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
using namespace std;

void inorder(BinaryTreeNode<int>* root, vector<int> & num)
  {
    if(!root) return ;
    inorder(root->left, num);
    num.push_back(root->data);
    inorder(root->right, num);
  }
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{   
    vector<int> num;
    inorder(root, num);
      int high=num.size()-1;
      int low=0;
      while(high>low)
      { int a=num[low]+num[high];
        if(a==k)
          return true;
        else if(a>k)
          high--;
       else 
          low++;
      }
      return false;   
}