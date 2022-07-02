// Solution link: https://takeuforward.org/data-structure/print-root-to-node-path-in-a-binary-tree/
// Leetcode link: https://www.interviewbit.com/problems/path-to-given-node/
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
#include<bits/stdc++.h>
using namespace std;

bool getPath(TreeNode<int> *root, vector<int> &ans, int x) {
    if(root) {
        bool isFound= false;
        isFound = getPath(root->left, ans, x, isFound);
        isFound = isFound || getPath(root->right, ans, x, isFound);
        if(root->data == x) {
            isFound = 1;
        } 
        if(isFound) ans.push_back(root->data);
        return isFound;
    }
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    getPath(root, ans, x);
    reverse(ans.begin(), ans.end());
    return ans;
}
