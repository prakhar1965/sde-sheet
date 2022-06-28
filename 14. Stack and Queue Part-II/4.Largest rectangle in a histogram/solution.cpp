// Solution link: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
// CodeStudio link: https://bit.ly/3qpxbR9
// Leetcode link: https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<bits/stdc++.h>
using namespace std;
int largestRectangle(vector < int > & heights) {
   // Write your code here.
    int max_area = 0;
    stack<int>s;
    int n = heights.size();
    for(int i=0; i<n; i++) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            int x = s.top();
            s.pop();
            int width;
            if(s.empty()) width = i;
            else width = i - s.top() - 1;
            int area = heights[x] * width;
            max_area = max(max_area, area);
        }
        s.push(i);
    }
    while(!s.empty()) {
        int x = s.top();
        s.pop();
        int width;
        if(s.empty()) width = i;
        else width = n - s.top() - 1;
        int area = heights[x] * width;
        max_area = max(max_area, area);
    }
    return max_area;
}