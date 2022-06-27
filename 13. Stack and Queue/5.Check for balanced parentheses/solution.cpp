// Solution link: https://takeuforward.org/data-structure/check-for-balanced-parentheses/
// CodeStudio link: https://bit.ly/3nr1RiO
// Leetcode link: https://leetcode.com/problems/valid-parentheses/
#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    stack<int>s;
    int len = expression.length();
    for(int i=0; i<len; i++) {
        if(expression[i] == '[' || expression[i] == '{' || expression[i] == '(') 
            s.push(expression[i]);
        else {
            if(s.empty()) return false;
            else if(expression[i] == ']' && s.top() != '[') return false;
            else if(expression[i] == '}' && s.top() != '{') return false;
            else if(expression[i] == ')' && s.top() != '(') return false;
            else s.pop();
        }
    }
    return s.empty()? true: false;
}