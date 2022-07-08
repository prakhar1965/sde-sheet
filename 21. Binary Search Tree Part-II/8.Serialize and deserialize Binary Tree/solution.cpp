// Solution link: https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree/
// CodeStudio link: https://bit.ly/3qr6pYD
// Leetcode link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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
#include<bits/stdc++.h>
using namespace std;
string serializeTree(TreeNode<int> *root)
{
    string serialized = "";
    if(!root) return serialized;
    queue<TreeNode<int>*>Q;
    Q.push(root);
    while(!Q.empty()) {
        TreeNode<int>* curr = Q.front();
        Q.pop();
        if(!curr)
            serialized.append("#,");
        else
            serialized.append(to_string(curr->data) + ',');
        if(curr) {
            Q.push(curr->left);
            Q.push(curr->right);
        }
    }
    return serialized;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    queue<TreeNode<int>*> Q;
    if(serialized.size() == 0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    Q.push(root);

    while(!Q.empty()) {
        TreeNode<int>* curr = Q.front();
        Q.pop();
        getline(s, str, ',');
            if(str == "#") {
                curr->left = NULL; 
            }
            else {
                TreeNode<int>* leftNode = new TreeNode<int>(stoi(str)); 
                curr->left = leftNode; 
                Q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                curr->right = NULL; 
            }
            else {
                TreeNode<int>* rightNode = new TreeNode<int>(stoi(str)); 
                curr->right = rightNode;
                Q.push(rightNode); 
            }
    }
    return root;
}



