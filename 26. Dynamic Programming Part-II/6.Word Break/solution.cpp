// CodeStudio link: https://bit.ly/3npqs7P
// Leetcode link: https://practice.geeksforgeeks.org/problems/word-break1352/1
#include<bits/stdc++.h>
using namespace std;
bool wordBreak(vector<string> & arr, int n, string & target) {

    int m = target.size();
    dp[0] = 1;
    vector<bool> dp(m+1, 0);
    for(int i=1; i<=m; i++) {
        for(int j=0; j<i; j++) {
            if(dp[j]) {
                for(string s: arr) {
                    if(s == target.substr(j, i-j)) dp[i] = 1, break;
                }
            }
        }
    }
    return dp[m];
}