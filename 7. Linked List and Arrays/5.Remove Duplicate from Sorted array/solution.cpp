// Solution link: https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/
// CodeStudio link: https://bit.ly/31Usllh
// Leetcode link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
int removeDuplicates(vector<int> &arr, int n) {
	
    int curr = 0;
    for(int i=0; i<n; i++) {
        int cnt = 0;
        while(i+1<n && arr[i] == arr[i+1]) i++;
        arr[curr++] = arr[i];
    }
    return curr;
}