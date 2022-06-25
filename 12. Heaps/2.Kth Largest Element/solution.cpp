// Solution link: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
// CodeStudio link: https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Leetcode link: https://leetcode.com/problems/kth-largest-element-in-an-array/
#include<bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>, greater<int>> min_heap;
    for(int x:arr) {
        max_heap.push(x);
        min_heap.push(x);
    }
    while(k--) {
        max_heap.pop();
        min_heap.pop();
    }
    return {min_heap.top(), max_heap.top()};
}