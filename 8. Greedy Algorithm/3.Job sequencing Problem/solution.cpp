// Solution link: https://takeuforward.org/data-structure/job-sequencing-problem/
// CodeStudio link: https://bit.ly/3K9XZfV
// Leetcode link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
#include<bits/stdc++.h>
using namespace std;
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
    });
    int time = 0;
    int n = jobs.size(), profit = 0;
    int maxDeadline = -1;
    for(int i=0; i<n; i++) maxDeadline = max(maxDeadline, jobs[i][0]);
    vector<int> deadlines(maxDeadline + 1, -1);
    for(int i=0; i<n; i++) {
        int j = jobs[i][0];
        while(j >= 1 && deadlines[j] != -1) j--;
        if(j != 0) {
            profit += jobs[i][1];
            deadlines[j] = i;
        }
    }
    return profit;
}

