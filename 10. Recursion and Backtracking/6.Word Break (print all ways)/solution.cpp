// CodeStudio link: https://bit.ly/3FxgW92
#include<bits/stdc++.h>
using namespace std;
void findWord(string &s, vector<string> &dictionary, int i, vector<string>&ans) {
    if(i > s.length())
        return;
    if(i == s.length()) {
        ans.push_back(s);
        return;
    }
    int n = dictionary.size();
    for(int k=0; k<n; k++) {
        int x = dictionary[k].length();
        int y = s.length() - i;
        // cout<<dictionary[k]<<" "<< s.substr(i,x);
        if(x <= y && dictionary[k] == s.substr(i,x)) {
            s.insert(i+x," ");
            findWord(s,dictionary,i+x+1, ans);
            s.erase(i+x,1);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    int n = dictionary.size();
    vector<string> dic;
    for(int i=0; i<n; i++) {
        string s = dictionary[i];
        bool isFound = false;
        for(string st : dic) {
            if(st == s) isFound = true;
        }
        if(isFound == 0)
         dic.push_back(s);
    }
//     cout<<dic.size();
    findWord(s, dic, 0, ans);
    return ans;
}
