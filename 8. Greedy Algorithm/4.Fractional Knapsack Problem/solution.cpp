// Solution link: https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/
// CodeStudio link: https://bit.ly/3I7fNXn
// Leetcode link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), [](pi &a, pi &b) {
        return ((double) a.second/(double)a.first) > ((double) b.second/(double)b.first);
    });   
    double maxVal = 0.0;
    int curr_wt = 0;
    for(int i=0; i<n; i++) {
        if(curr_wt + items[i].first <= w) {
            curr_wt += items[i].first;
            maxVal += items[i].second;
        } else {
            int remaining_wt = w - curr_wt;
            maxVal += (items[i].second/(double)items[i].first) * (double) remaining_wt;
            break;
        }
    }
    return maxVal;
}