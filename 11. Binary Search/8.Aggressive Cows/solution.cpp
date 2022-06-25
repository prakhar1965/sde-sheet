// Solution link: https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
// CodeStudio link: https://bit.ly/3zV52ob
// Leetcode link: https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &positions, int c, int mid) {
    int chessPlayer = 1;
    int lastPos = positions[0];
    for(int i=1; i<positions.size(); i++) {
        if(positions[i] - lastPos >= mid) {
            chessPlayer++;
            lastPos = positions[i];
        }
    }
    if(chessPlayer >= c) return true;
    else return false;
}
int chessTournament(vector<int> positions , int n ,  int c){

    sort(positions.begin(), positions.end());
    int low = 1, high = positions[n-1] - positions[0];
    int ans = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(isPossible(positions,c,mid)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}