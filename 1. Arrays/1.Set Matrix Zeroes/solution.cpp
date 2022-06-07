// Solution link: https://takeuforward.org/data-structure/set-matrix-zero/
// CodeStudio link: https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Leetcode link: https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h> 
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	bool firstColIsZero = false;

	for (int i=0; i<rows; i++) {
		if(matrix[i][0] == 0) 
		  	firstColIsZero = true;
		for (int j=1; j<cols; j++) {
			if(matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for(int i=rows-1; i >=0; i--) {
		
		for(int j=cols-1; j >=1; j--) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
			 	matrix[i][j] = 0;
		}

		if(firstColIsZero) 
			matrix[i][0] = 0;
	}
}