// Solution link: https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
// CodeStudio link: https://bit.ly/3qoj5iQ
// Leetcode link: https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{   
    int k , l;
    for(k=n-2; k>= 0; k--)
    {   
        if(permutation[k] < permutation[k+1]) 
        {
            break;
        }
    }

    if(k < 0) 
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    for(l=n-1; l>k; l--)
    {
        if(permutation[l] > permutation[k])
        {
           break;
        }     
    }
    swap(permutation[k],permutation[l]);
    reverse(permutation.begin()+k+1, permutation.end());
   return permutation;
}

// int main() {
//     int n;
//     cin>>n;

//     vector<int> arr(n);
//     for(int i=0;i<n;i++) 
//     {
//         cin>>arr[i];
//     }
//     nextPermutation(arr, n);
     
//     for(int x: arr) cout<<x<<" ";
     
// }