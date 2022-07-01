// CodeStudio link: https://bit.ly/3zXpYeb
// Leetcode link: https://leetcode.com/problems/string-to-integer-atoi/
#include<bits/stdc++.h>
using namespace std;
int atoi(string str) {
    int res = 0, n = str.length();
    if(n < 1) return 0;
    int sign = (str[0] == '-') ? -1 : 1;
    for(int i=0; i<n; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            res = res*10 + (str[i] - '0') * sign;
        }
    }
    return res;
}