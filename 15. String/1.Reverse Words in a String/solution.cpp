// Solution link: https://takeuforward.org/data-structure/reverse-words-in-a-string/
// CodeStudio link: https://bit.ly/3FmKc1X
// Leetcode link: https://leetcode.com/problems/reverse-words-in-a-string/
#include<bits/stdc++.h>
using namespace std;
string reverseString(string str)
{   
    int n = str.length();
    string reversed = "";
    int start = -1, curr_len = 0;
    for(int i=n-1; i>=0; i--) 
    {
        if(str[i] == ' ' && curr_len != 0) 
        {
            reversed.append(str.substr(i+1, curr_len));
            reversed.append(" ");
            curr_len = 0;
        }
        curr_len = (str[i] == ' ') ? 0 : curr_len + 1;   
    }
    if(curr_len != 0) reversed.append(str.substr(0, curr_len));
    return reversed;
}