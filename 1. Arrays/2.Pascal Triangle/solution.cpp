// Solution link: https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
// CodeStudio link: https://bit.ly/3rhv153
// Leetcode link: https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>
using namespace std; 
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long>> pascalTriangle(n);

  if(n >= 1) pascalTriangle[0].push_back(1);

  for(int i=2; i<=n; i++) 
  {
      for(int j=1; j<=i; j++) 
      { 
          long long presc1 = (j == 1) ? 0 : pascalTriangle[i-2][j-2];
          long long presc2 = (j == i) ? 0 : pascalTriangle[i-2][j-1];

          pascalTriangle[i-1].push_back(presc1+presc2);
      }
     
  }

  return pascalTriangle;
}

// int main()
// {
//     int n;
//     cin>>n;

//     printPascal(n);
// }