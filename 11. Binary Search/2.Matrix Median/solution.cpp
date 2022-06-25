// CodeStudio link: https://bit.ly/33AHZTz
// Leetcode link: https://www.interviewbit.com/problems/matrix-median/
#include<bits/stdc++.h>
using namespace std;
int getMedian(vector<vector<int>> &matrix)
{   int n = matrix.size(), m = matrix[0].size();
    int mine = INT_MAX;
    int maxe = INT_MIN;
    int mide = (n*m)/2 + 1;
    for(int i=0; i<n; i++) {
        mine = min(matrix[i][0], mine);
        maxe = max(matrix[i][m-1], maxe);
    }
    while(mine < maxe) {
        int cnt = 0;
        int mid = (mine+maxe)/2;
        for(int i=0; i<n; i++) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
       if(cnt < mide) mine = mid+1;
       else maxe = mid;
    }
    return mine;
}