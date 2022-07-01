// CodeStudio link: https://bit.ly/3Grdrlv
// Leetcode link: https://leetcode.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;
int expand(string s, int l, int h)
{
    while(l >= 0 && h < s.length() && s[l] == s[h]) 
    {
        l--;
        h++;
    }
    return h - l - 1;
}
string longestPalinSubstring(string str)
{
    int n = str.length();
    if(n < 1) return "";
    int start = 0,end = 0;
    for(int i=0; i<n; i++) 
    {
        int len1 = expand(str, i, i);
        int len2 = expand(str, i, i+1); 
        int len = max(len1, len2);
        if(len > (end - start + 1))
        {
            start = i - (len - 1)/2;
            end = i + len/2;
        }
    }
    return str.substr(start, end - start + 1);
}