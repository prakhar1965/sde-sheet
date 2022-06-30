// Solution link: https://takeuforward.org/data-structure/n-meetings-in-one-room/
// CodeStudio link: https://bit.ly/3I2iPvN
// Leetcode link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int maximumActivities(vector<int> &start, vector<int> &finish) {

    vector<pi> activity;
    int n = start.size();
    for(int i=0; i<n; i++) {
        activity.push_back({start[i], finish[i]});
    }
    sort(activity.begin(), activity.end(), [](pi &a, pi &b){
        return a.second < b.second;
    });

    int maxActivity = 0, lastEndTime = -1;
    for(int i=0; i<n; i++) {
        if(activity[i].first >= lastEndTime) {
            maxActivity++;
            lastEndTime = activity[i].second;
        }
    }
    return maxActivity;
}