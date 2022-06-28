// Solution link: https://takeuforward.org/data-structure/n-meetings-in-one-room/
// CodeStudio link: https://bit.ly/3zXdqn5
// Leetcode link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define pii pair<int,pi>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<pii> sortedMeeting;
    for(int i=1; i<=n; i++) sortedMeeting.push_back(make_pair(i, make_pair(start[i-1],end[i-1])));

    sort(sortedMeeting.begin(), sortedMeeting.end(), [](const pii &a, const pii &b){
        pi aTime = a.second;
        pi bTime = b.second;
        return aTime.second == bTime.second ? a.first < b.first : aTime.second < bTime.second;
    });
    vector<int> ans;
    int lastEndTime = sortedMeeting[0].second.second;
    ans.push_back(sortedMeeting[0].first);
    for(int i=1; i<n; i++) {
        int startTime = sortedMeeting[i].second.first;
        if(startTime > lastEndTime) {
            ans.push_back(sortedMeeting[i].first);
            lastEndTime = sortedMeeting[i].second.second;
        }
    }
    return ans;
}
// int main() {
//     vector<int> a = {1,2,3};
//     vector<int> b = {4,4,4};
//     vector<int> ans = maximumMeetings(a,b);
//     for(int x: ans) cout<<x<<" ";
// }