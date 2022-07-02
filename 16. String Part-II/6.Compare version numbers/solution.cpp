// CodeStudio link: https://bit.ly/3GwYuys
// Leetcode link: https://leetcode.com/problems/compare-version-numbers/
#include<bits/stdc++.h>
using namespace std;
int compareString(string &x, string &y) {
    if(x == "") x.push_back('0');
    if(y == "") y.push_back('0');
    int n = x.length();
    int m = y.length();
    if(n>m) return 1;
    else if(n<m) return -1;

    for(int i=0; i<n; i++) {
        if(x[i] > y[i]) return 1;
        else if(x[i] < y[i]) return -1;
    }
    return 0;
    
}
int compareVersions(string a, string b) {
    int n = a.length();
    int m = b.length();

    int i = 0,j = 0;
    while(i<n || j<m) {
        string x ="",y = "";
        while(i<n && a[i] != '.') {
            x.push_back(a[i]);
            i++;
        }
        while(j<m && b[j] != '.') {
            y.push_back(b[j]);
            j++;
        }
        int com = compareString(x,y);
        if(com == 1) return 1;
        else if(com == -1) return -1;
         i++,j++;
    }
    return 0;
}

int main(){
    string a = "1.0.0";
    string b = "1";
    cout<<compareVersions(a,b);
}
