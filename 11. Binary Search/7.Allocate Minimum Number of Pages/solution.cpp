// Solution link: https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
// CodeStudio link: https://bit.ly/3FrKxk7
// Leetcode link: https://www.interviewbit.com/problems/allocate-books/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &time, int mid, int n) {
    int sum = 0, cnt = 0;
        for(int i=0; i<time.size(); i++) {
           if(sum + time[i] > mid) {
             cnt++;
             sum = time[i];
             if(sum > mid) {
                return false;
             }
           }
           sum += time[i];
        }
    if(cnt < n) return true;
    else return false;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    int chapters = time.size();
    int low = INT_MAX, high = 0;
    for(int i=0; i<chapters; i++) {
        low = min(low, time[i]);
        high += time[i];
    }
    int ans = -1;
    while(low <= high) {
        int mid = (low+high)/2;
        
        if(isPossible(time, mid, n)) {
            high = mid-1;
            ans = mid;
        }
        else
            low = mid+1;
    }
    return ans;
}