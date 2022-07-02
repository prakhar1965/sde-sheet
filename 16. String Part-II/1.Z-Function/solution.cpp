// CodeStudio link: https://bit.ly/3qs24UM
// Leetcode link: https://leetcode.com/problems/implement-strstr/

#include<bits/stdc++.h>
using namespace std;
void calculateZfunction(string s, vector<int> &z) 
{
    int n = s.length();
    for(int i=1, l=0, r=0; i<n; i++)
    {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i + z[i] - 1 > r) 
        {
            l = i;
            r = i+z[i]-1;
        }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
	vector<int> z(n+m, 0);
    p.append(s);
    calculateZfunction(p, z);
    for(int x: z) cout<<x<<" ";
    int cnt = 0;
    for(int i=m; i<n+m; i++)
    {
        if(z[i] >= m) cnt++;
    }
    return cnt;
}
