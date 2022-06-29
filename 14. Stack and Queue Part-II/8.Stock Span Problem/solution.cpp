// CodeStudio link: https://bit.ly/3GvBtMk
// Leetcode link: https://leetcode.com/problems/online-stock-span/
#include<bits/stdc++.h>
using namespace std;
vector<int> findSpans(vector<int> &price) {
    stack<int>s;
    vector<int> ans;
    s.push(-1);
    int n = price.size();
    for(int i=0; i<n; i++) {
        while(s.top() != -1 && price[s.top()] <= price[i]) {
            s.pop();
        }
        ans.push_back(i - s.top());
        s.push(i); 
    }
    return ans;
}