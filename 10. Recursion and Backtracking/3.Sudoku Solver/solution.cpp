// Solution link: https://takeuforward.org/data-structure/sudoku-solver/
// CodeStudio link: https://bit.ly/31Z5Iwe
// Leetcode link: https://leetcode.com/problems/sudoku-solver/
#include<bits/stdc++.h>
using namespace std;
bool isItCorrect(int matrix[9][9], int i, int j, int n) {
     for(int k=0;k<9;k++){
        if(matrix[i][k]==n || matrix[k][j]==n){
            return false;
        }
    }
    int si=i-i%3;
    int sj=j-j%3;
    for(int i=si;i<si+3;i++){
        for(int j=sj;j<sj+3;j++){
            if(matrix[i][j]==n){
                return false;
            }
        }
    }
    return true;
}
bool solve(int matrix[9][9]) {
    
    for(int i = 0 ;i<9;i++){
 for(int j = 0 ; j<9;j++){
  if(matrix[i][j]==0){
   for(int no= 1 ;no<=9 ;no++){
    if(isItCorrect(matrix,i,j,no)){
    matrix[i][j]=no;
     if(solve(matrix)==true)
      return true;
     else
      matrix[i][j]=0;
    }
   }
   return false;
  }
 }
}
return true;
}
bool isItSudoku(int matrix[9][9]) {
    if(solve(matrix) == true)
            return true;
    return false;
}

