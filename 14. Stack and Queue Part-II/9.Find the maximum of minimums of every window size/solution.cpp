// CodeStudio link: https://bit.ly/3zUYLZz
#include<bits/stdc++.h>
using namespace std;
vector<int> maxMinWindow(vector<int> a, int n) {
    stack<int>s;
    vector<int> minRange(n);

    for(int i=0; i<=n; i++) {

        while(!s.empty() && (i == n || a[i] < a[s.top()])) {
            int width;
            int x = s.top();
            s.pop();
            if(s.empty()) width = i;
            else width = i-s.top()-1;
            minRange[x] = width;
        }
        s.push(i);
    }
    vector<int> ans(n, INT_MIN);
    for(int i=0; i<n; i++) {
        ans[minRange[i]-1] = max(ans[minRange[i]-1], a[i]);
    }
    for(int i=n-2; i>=0; i--) {
         ans[i] = max(ans[i+1], ans[i]);
    }
    // for(int x: ans) cout<<x<<" ";
    return ans;
}
// int main() {
//     vector<int> arr = {80 -10 23 -3 22 77 -69 74 -55 45};
//     maxMinWindow(arr,arr.size());
// }