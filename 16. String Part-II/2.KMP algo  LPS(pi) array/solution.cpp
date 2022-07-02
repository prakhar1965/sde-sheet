// CodeStudio link: https://bit.ly/31VF1s6
// Leetcode link: https://leetcode.com/problems/implement-strstr/
#include<bits/stdc++.h>
using namespace std;
bool findPattern(string p, string s)
{
    int m = p.length();
    int n = s.length();

    for(int i=0; i+m-1<n;i++) {
        if(s.substr(i,m) == p)
            return true;
    }
    return false;
}