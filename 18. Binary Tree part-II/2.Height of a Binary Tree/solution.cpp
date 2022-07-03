// Solution link: https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/
// CodeStudio link: https://bit.ly/3qoOEco
// Leetcode link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include<bits/stdc++.h>
using namespace std;

struct node {
    int start;
    int end;
    int height;
};
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){

   node root;
   root.end = N-1;
   root.start = 0;
   root.height = 0;
   queue<node> Q;
   Q.push(root);
   int pos[N+1];
   for(int i=0; i<N; i++) pos[inorder[i]] = i;
   int maxHeight = 0;
   for(int i=0; i<N; i++) {
      int curr = levelOrder[i];
      node curr_node = Q.front();
      Q.pop();
      int curr_pos = pos[curr];
      if(curr_pos > curr_node.start) {
        node newnode;
        newnode.start = curr_node.start;
        newnode.end = curr_pos - 1;
        newnode.height = curr_node.height + 1;
        maxHeight = max(maxHeight, newnode.height);

        Q.push(newnode);
      }
      if(curr_pos < curr_node.end) {
        node newnode;
        newnode.start = curr_pos+1;
        newnode.end = curr_node.end;
        newnode.height = curr_node.height + 1;
        maxHeight = max(maxHeight, newnode.height);

        Q.push(newnode);
      }
   }
    return maxHeight;
}

