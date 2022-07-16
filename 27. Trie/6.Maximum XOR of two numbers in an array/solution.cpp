// Solution link: https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/
// CodeStudio link: https://bit.ly/3rjEYis
// Leetcode link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include<bits/stdc++.h>
using namespace std;
 class node{
    public:
    node() {
        left = NULL;
        right = NULL;
    }
    node* left;
    node* right;
};
void insertInTrie(int x, node* root) {
    
    for(int i=31; i>=0; i--) {
        int j = (x>>i & 1);
        if(j) {
            if(!root->right) {
                node* newNode = new node();
                root->right = newNode;
            }
            root = root->right;
        } else {
            if(!root->left) {
                node* newNode = new node();
                root->left = newNode; 
            }
            root = root->left;
        }
    }
}
int findMaxXor(node* root, int x) {
    int val = 0;
    for(int i=31; i>=0; i--) {
        int j = (x>>i) & 1;
        if(j) {
            if(root->left) {
                val = val | (1 << i);
                root = root->left;
            } else {
                root = root->right;
            }
        } else {
            if(root->right) {
                val = val | (1 << i);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    return val;
}
int maximumXor(vector<int> A)
{
    int n = A.size();
    int maxXor = 0;
    node *head = new node();
    insertInTrie(A[0], head);
    for(int i=1; i<n; i++) {
        maxXor = max(maxXor, findMaxXor(head, A[i]));
        insertInTrie(A[i], head);
    }
    return maxXor;
}