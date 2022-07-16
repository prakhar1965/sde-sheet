// CodeStudio link: https://bit.ly/3KbHhN4
// Leetcode link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
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
vector<int> maxXorQueries(vector<int> &A, vector<vector<int>> &queries)
{
    int n = A.size();
    node *head = new node();
    vector<vector<int>>ans;
    for(int i=0; i<queries.size(); i++) {
        queries[i].push_back(i);
    }
    sort(A.begin(),A.end());
    sort(queries.begin(),queries.end(),[](vector<int>a, vector<int>b){
        return a[1]<b[1];
    });
    int j=0, Q = queries.size();
    while(j<Q && queries[j][1] < A[0]) {
        ans.push_back({queries[j][2], -1});
        j++;
    }
    for(int i=0; i<n; i++) {
        while(j<Q && queries[j][1] < A[i]) {
        ans.push_back({queries[j][2], findMaxXor(head,queries[j][0])});
        j++;
      }
        insertInTrie(A[i], head);
    }
    while(j<Q) {
        ans.push_back({queries[j][2], findMaxXor(head,queries[j][0])});
        j++;
      }
    vector<int>ans1;
    sort(ans.begin(),ans.end(),[](vector<int>a, vector<int>b){
        return a[0]<b[0];
    });
    for(auto v: ans) ans1.push_back(v[1]);
    return ans1;
}