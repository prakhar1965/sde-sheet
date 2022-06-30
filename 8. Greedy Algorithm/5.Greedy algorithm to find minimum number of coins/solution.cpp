// Solution link: https://takeuforward.org/data-structure/find-minimum-number-of-coins/
// CodeStudio link: https://bit.ly/3nquVHj
// Leetcode link: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
#include<bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount) 
{
    int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int minCoins = 0, i = 0;
    while(amount > 0) {
        while(amount < arr[i]) i++;
        int x = amount / arr[i];
        minCoins += x; 
        amount -= x*arr[i];
    }
    return minCoins;
}
