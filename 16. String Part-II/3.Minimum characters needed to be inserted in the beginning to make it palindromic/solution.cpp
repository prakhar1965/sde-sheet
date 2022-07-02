// CodeStudio link: https://bit.ly/34RE855
// Leetcode link: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
#include<bits/stdc++.h>
using namespace std;

int minCharsforPalindrome(string str) {

    int n = str.length();
    vector<int> pre(n,0);
    string str2 = str;
    reverse(str.begin(), str.end());
    str2 = str2 + "$" + str;
    int m = str2.length();
    vector<int> kmp(m, 0);
    for(int i=1; i<m; i++) {
        int len = kmp[i-1];
        while(len > 0 && str2[len] != str2[i]) len = kmp[len-1];

        if(str2[len] == str2[i]) len++;
        kmp[i] = len;
    }
    
    return n - kmp[m-1];
}


