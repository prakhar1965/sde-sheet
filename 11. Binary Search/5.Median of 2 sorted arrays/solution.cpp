// Solution link: https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
// CodeStudio link: https://bit.ly/3Ka3jQr
// Leetcode link: https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;
double median(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    if(n>m) return median(b,a);
    int low = 0, high = n;
    while(low <= high) {
        int mid1 = (low+high)/2;
        int mid2 = (n + m + 1)/2 - mid1;

        int left1 = mid1 == 0 ? INT_MIN : a[mid1-1];
        int left2 = mid2 == 0 ? INT_MIN : b[mid2-1];
        int right1 = mid1 == n ? INT_MAX: a[mid1];
        int right2 = mid2 == m ? INT_MAX : b[mid2];

        if(left1 <= right2 && left2 <= right1) {
            if((n+m)%2 == 0) {
                return (max(left1,left2) + min(right1,right2))/2.0;
            } else 
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
