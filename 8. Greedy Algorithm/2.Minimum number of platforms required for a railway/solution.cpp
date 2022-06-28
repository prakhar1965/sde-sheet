// Solution link: https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
// CodeStudio link: https://bit.ly/3npx0mW
// Leetcode link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    if(n == 0) return 0;
    sort(at, at+n);
    sort(dt, dt+n);

    int maxPlateform = 1, curr_plateform = 1;
    int i = 1, j = 0;
    while(i<n && j <n) {
        if(at[i] <= dt[j]) {
            curr_plateform++;
            i++;
        } else {
            curr_plateform--;
            j++;
        }
        maxPlateform = max(maxPlateform, curr_plateform);
    } 
    return maxPlateform;
}