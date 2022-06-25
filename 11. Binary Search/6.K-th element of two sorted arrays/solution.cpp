// Solution link: https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/
// CodeStudio link: https://bit.ly/3qm0cgu
// Leetcode link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include<bits/stdc++.h>
using namespace std;
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {

    int low = max(0, k-n), high = min(m, k);
    while(low <= high) {
        int mid1 = (low+high)/2;
        int mid2 = k - mid1;

        int left1 = mid1 == 0 ? INT_MIN : row1[mid1-1];
        int left2 = mid2 == 0 ? INT_MIN : row2[mid2-1];
        int right1 = mid1 == m ? INT_MAX: row1[mid1];
        int right2 = mid2 == n ? INT_MAX : row2[mid2];

        if(left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        }
        else if (left1 > right2) {
            high = mid1 - 1;
        }
        else 
            low = mid1 + 1;
    }
    return 0;
}