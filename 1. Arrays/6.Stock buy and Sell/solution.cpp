// Solution link: https://takeuforward.org/data-structure/stock-buy-and-sell/
// CodeStudio link: https://bit.ly/3GsANaD
// Leetcode link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{   int n = prices.size();
    int minBuyPrice = INT_MAX;
    int maxProfit = 0;
    for(int i=0; i<n; i++)
    {
        int sellPrice = prices[i];
        int maxProfitBySelling = sellPrice - minBuyPrice;
        minBuyPrice = min(minBuyPrice, prices[i]); 
        maxProfit = max(maxProfit, maxProfitBySelling);
    }
    return maxProfit;
}