// CodeStudio link: https://bit.ly/3GlNN1D
// Leetcode link: https://leetcode.com/problems/longest-common-prefix/
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{ 
    string ans = "";
    if(n<1) return ans;
    int start = 0;
    while(1) {
        char x;
        if(start < arr[0].length())
        {
            x = arr[0][start];
        } 
        else break;
        bool isCommon = true;
        for(int i=1; i<n; i++) {
            if(start >= arr[i].length() || arr[i][start] != x) {
                isCommon = false;
                break;
            }
        }
        if(isCommon) start++; else break;
    }
    return arr[0].substr(0, start);
}


