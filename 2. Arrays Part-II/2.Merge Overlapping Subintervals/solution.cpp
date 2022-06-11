// Solution link: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
// CodeStudio link: https://bit.ly/3rj9LvO
// Leetcode link: https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](vector<int> &int1, vector<int> &int2)
    {
        return int1[0] < int2[0];
    });
    vector<vector<int>> mergeInterval;

    int sizeOfIntervals = intervals.size();

    for(int i=0; i<sizeOfIntervals; i++)
    {
        int intStart = intervals[i][0];
        int intEnd = intervals[i][1];
        while(i+1<sizeOfIntervals && intervals[i+1][0] <= intEnd){
            i++;
            intEnd = max(intEnd, intervals[i][1]);
        }
        mergeInterval.push_back({intStart, intEnd});
    }
    return intervals = mergeInterval;
}

// int main()
// { 
//     vector<vector<int>> arr = {{1,4}, {3,5}, {6,8},{8,9},{10,12}};
//     vector<vector<int>> arr1 = mergeIntervals(arr);

//     for(auto x: arr1){
//         for(auto y:x){
//             cout<<y<<" ";
//         }
//         cout<<endl;
//     }
// }
