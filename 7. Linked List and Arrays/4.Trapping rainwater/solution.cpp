// Solution link: https://takeuforward.org/data-structure/trapping-rainwater/
// CodeStudio link: https://bit.ly/3KcxExJ
// Leetcode link: https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    stack<int>s;
    long area = 0;
    for(int i=0;i<n;i++) {
          while(!s.empty() && arr[i] > arr[s.top()]) {
                int x = s.top();
                s.pop();
                if(!s.empty()) {
                    area += (min(arr[s.top()],arr[i]) - arr[x])*(i-s.top()-1);
                }
            }
        s.push(i);
    }
    return area;
}