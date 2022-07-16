// Solution link: https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
// CodeStudio link: https://bit.ly/3fmd28k
// Leetcode link: https://practice.geeksforgeeks.org/problems/power-set4302/1#
#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* child[51];

    TrieNode* getNode(int c) {
        return child[c];
    }

    void put(int c, TrieNode* node) {
        child[c] = node;
    }

    bool isPresent(int c) {
        return child[c] != NULL;
    }
};
void generatePowerSet(int idx, vector<int> &v, vector<vector<int>> &powerSet, vector<int> &currSet, TrieNode* currNode) {
    if(idx == v.size()) {
        powerSet.push_back(currSet);
        return;
    }
    generatePowerSet(idx+1, v, powerSet, currSet);
    for(int i=idx; i<v.size(); i++) {
        currSet.push_back(v[idx]);
        generatePowerSet(idx+1,v,powerSet, currSet);
        currSet.pop_back();
    }
}

vector<vector<int>> pwset(vector<int>v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    TrieNode* root = new TrieNode();
    vector<vector<int>> powerSet;
    vector<int>currSet;
    generatePowerSet(0, v, powerSet, currSet, root);
    return powerSet;
}