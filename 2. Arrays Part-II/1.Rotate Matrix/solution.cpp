// Solution link: https://takeuforward.org/data-structure/rotate-image-by-90-degree/
// CodeStudio link: https://bit.ly/3rhVUWx
// Leetcode link: https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>
using namespace std;

int dir[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

pair<int,int> getNextIndex(int i,int j,int lvl, int n)
{
    
}
void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int levels = n/2;

    for(int i=0; i<levels; i++)
    {
        int prev = mat[i+1][i];
        int noOfElementsInLevel = n- 2*i;
        if(noOfElementsInLevel > 1)
        {  
            int start_x = i;
            int start_y = i;

            while()
        }

    }
}