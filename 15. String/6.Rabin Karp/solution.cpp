// CodeStudio link: https://bit.ly/3FvnLaN
// Leetcode link: https://leetcode.com/problems/repeated-string-match/discuss/416144/Rabin-Karp-algorithm-C%2B%2B-implementation
#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int p = 31;
vector<int> stringMatch(string &str, string &pat) {
    vector<int> matchingStart;
    int n = str.length();
    vector<long long> hash(n+1,0);
    vector<long long> power(n+1);
    power[0] = 1LL;
    for(int i=1; i<=n; i++) {
        power[i] = (power[i-1]*31) % m;
    }
    for(int i=0; i<n; i++) 
    {
        hash[i+1] = (hash[i] + (str[i] - 'A' + 1)* power[i]) % m;
    }
    long long patHash = 0;
    for(int i=0; i<pat.size(); i++) 
    {
        patHash = (patHash + (pat[i]-'A' +1)* power[i]) % m;
    }
    cout<<"pathash"<<patHash;
    for(int i=0; i+pat.size()-1 < n; i++)
    {
        long long curr_hash = (hash[i+pat.size()] - hash[i] + m)% m;
        cout<<"curr_hash"<<curr_hash<<" "<<(patHash*power[i])%m<<endl;

        if(curr_hash == (patHash*power[i])%m) {
            matchingStart.push_back(i);
        }
    }
    return matchingStart;
}

// int main(){
//     string a = "CODENCODEX\n";
//     string b = "CODE\n";
//     stringMatch(a, b);
// }