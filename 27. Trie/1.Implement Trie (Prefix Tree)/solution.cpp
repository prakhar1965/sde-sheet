// Solution link: https://takeuforward.org/data-structure/implement-trie-1/
// CodeStudio link: https://bit.ly/33wIn5x
// Leetcode link: https://leetcode.com/problems/implement-trie-prefix-tree/
#include<bits/stdc++.h>
using namespace std;
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
     TrieNode() {
        endWord = 0;
     }
     char c;
     vector<TrieNode*> children;
     bool endWord;

};

class Trie {
    TrieNode* head;
public:

    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode();
        head->c = '$';
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
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
            if(!found) return false;
        }
        return curr->endWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* curr = head;
        for(int i=0; i<n; i++) {
            bool found = 0;
            for(auto x: curr->children) {
                if(x->c == prefix[i]) {
                    curr = x;
                    found = 1;
                    break;
                }
            }
            if(!found) return false;
        }
        return curr->endWord || !curr->children.empty();
    }
};