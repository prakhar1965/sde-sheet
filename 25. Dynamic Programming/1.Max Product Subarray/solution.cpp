// Solution link: https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/
// CodeStudio link: https://bit.ly/3fqz6OS
// Leetcode link: https://leetcode.com/problems/maximum-product-subarray/
int maximumProduct(vector<int> &arr, int n)
{
    int maxProd = arr[0], minProd = arr[0];
    int ans = arr[0];
    for(int i=1; i<n; i++) {
        int x = max(arr[i], max(arr[i]*maxProd, arr[i]*minProd));
        minProd = min(arr[i],min(arr[i]*maxProd, arr[i]*minProd));
        maxProd = x;
        ans = max(ans, maxProd);
    }
    return ans;
}
