// CodeStudio link: https://bit.ly/3qrU6vb
// Leetcode link: https://bit.ly/3n3kedU
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
     TrieNode() {
        endWord = 0;
     }
     char c;
     vector<TrieNode*> children;
     bool endWord;

};
 void insert(string word, TrieNode* head) {
        int n = word.length();
        TrieNode* curr = head;
        for(int i=0; i<n; i++) {
            bool found = 0;
            for(auto x: curr->children) {
                if(x->c == word[i]) {
                    curr = x;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                TrieNode* newNode = new TrieNode();
                newNode->c = word[i];
                curr->children.push_back(newNode);
                curr = newNode;
            }
        }
        curr->endWord = 1;
    }

string findCompleteString(TrieNode* root) {
    string ans(1,root->c);
    string maxLen = "";
    for(TrieNode* node: root->children) {
        if(node->endWord) {
            string childString = findCompleteString(node);
            if(childString.length() > maxLen.length()) {
                maxLen = childString;
            } else if(childString.length() == maxLen.length()) {
                if(childString<maxLen)
                    maxLen = childString;
            }
        }
    }
    ans += maxLen;
    return ans;
}
string completeString(int n, vector<string> &a){
    TrieNode* head= new TrieNode();
    head->c = '$';
    for(int i=0; i<n; i++) {
        insert(a[i], head);
    }

    string ans = findCompleteString(head);
    return (ans == "$")? "None": ans.substr(1,ans.length()-1);
}