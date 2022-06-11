// Solution link: https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
// CodeStudio link: https://bit.ly/3Gtjwhl
// Leetcode link: https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	if(n == 0) return 1;
    long long exp = modularExponentiation(x,n/2,m);
    exp = (exp*exp)%m;
    if(n%2 == 1) exp = (exp*x)%m;
    return exp;
}