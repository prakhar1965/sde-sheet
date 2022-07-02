// CodeStudio link: https://bit.ly/3K8Uwyi
// Leetcode link: https://leetcode.com/problems/count-and-say/
#include<bits/stdc++.h>
using namespace std;
string writeAsYouSpeak(int n) 
{
    string ans = "1";
    if(n == 1) return ans;
    while(--n) {
        int m = ans.length();
        string ans1 = "";
        for(int i=0; i<m; i++) {
            int cnt = 0;
            char start = ans[i];
            while(i+1 < m && ans[i] == ans[i+1]) i++,cnt++;
            ans1.push_back('1' + cnt);
            ans1.push_back(start);
        }
        ans = ans1;
    }
    return ans;
}