// CodeStudio link: https://bit.ly/3KdiUPp
// Leetcode link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include<bits/stdc++.h>
using namespace std;
class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    Kthlargest(int k, vector<int> &arr) {
       int n = arr.size();
       int i = 0;
       for(i=0; i<k && i<n; i++) {
        minHeap.push(arr[i]);
       }
       while(i<n) {
         add(arr[i++]);
       }
    }

    void add(int num) {
        int x = minHeap.top();
        if(num > x) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    int getKthLargest() {
       return minHeap.top();
    }

};