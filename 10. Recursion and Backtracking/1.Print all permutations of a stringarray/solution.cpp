// Solution link: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
// CodeStudio link: https://bit.ly/3fmwxNV
// Leetcode link: https://leetcode.com/problems/permutations/
#include<bits/stdc++.h>
using namespace std;
void findPerms(int idx, string &s, vector<string> & ans) {
    if(idx == s.length()) {
        ans.push_back(s);
        return;
    }
    for(int i=idx; i<s.length(); i++) {
        swap(s[idx], s[i]);
        findPerms(idx+1, s, ans);
        swap(s[idx], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    
    vector<string> ans;
    findPerms(0, s, ans);
    return ans;
}