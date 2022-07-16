// Solution link: https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/
// CodeStudio link: https://bit.ly/3zVV1XD
// Leetcode link: https://bit.ly/3ocRQW0
#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode* child[26];

    TrieNode* getNode(char c) {
        return child[c - 'a'];
    }

    void put(char c, TrieNode* node) {
        child[c-'a'] = node;
    }

    bool isPresent(char c) {
        return child[c-'a'] != NULL;
    }
};

int distinctSubstring(string &word) {
    int n = word.length();
    int cnt = 0;
    TrieNode * root = new TrieNode();
    for(int i=0; i<n; i++) {
        TrieNode* curr = root;
        for(int j=i; j<n; j++) {
            if(!curr->isPresent(word[j])) {
                curr->put(word[j], new TrieNode());
                cnt++;
            }
            curr = curr->getNode(word[j]);
        }
    }
    return cnt;
}
