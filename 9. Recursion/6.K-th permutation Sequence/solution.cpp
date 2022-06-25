// Solution link: https://takeuforward.org/data-structure/find-k-th-permutation-sequence/
// CodeStudio link: https://bit.ly/3KcCP0D
// Leetcode link: https://leetcode.com/problems/permutation-sequence/
#include<bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {
    string ans = "";
    int fact = 1;
    vector<int> numbers;
    for(int i=1; i<n; i++) {
        fact = fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k-1;
    while(1) {
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact);
        if(numbers.size() == 0) break;
        k = k%fact;
        fact = fact / numbers.size();
    }
    return ans;
}
