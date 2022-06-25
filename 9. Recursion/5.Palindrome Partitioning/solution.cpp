// Solution link: https://takeuforward.org/data-structure/palindrome-partitioning/
// CodeStudio link: https://bit.ly/3HZPNgs
// Leetcode link: https://leetcode.com/problems/palindrome-partitioning/
#include<bits/stdc++.h>
using namespace std;
int dp[16][16];
void partitionUtil(int idx,string &s,vector<vector<string>> &parString, vector<string> &curr_str) {
    if(idx == s.length()) parString.push_back(curr_str);

    for(int i = idx; i<s.length(); i++) {
        if(dp[idx][i] == 1) {
            curr_str.push_back(s.substr(idx, i-idx+1));
            partitionUtil(i+1,s, parString, curr_str);
            curr_str.pop_back();
        }
    }
    
}
vector<vector<string>> partition(string &s) 
{   for(int i=1; i<=s.length(); i++) {
    for(int j=0; j+i<=s.length(); j++) {
        if(i == 1) dp[j][j+i-1] = 1;
        else {
            int start = j, end = j+i-1;
            if(i == 2 && s[start] == s[end]) dp[j][end] = 1; 
            else if(s[start] == s[end] && dp[start+1][end-1] == 1) dp[start][end] = 1;
        }
    }
}
    vector<vector<string>> parStrings;
    vector<string> curr_string;
    partitionUtil(0,s,parStrings, curr_string);
    return parStrings;
}
