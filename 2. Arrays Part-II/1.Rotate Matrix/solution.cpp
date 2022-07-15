// Solution link: https://takeuforward.org/data-structure/rotate-image-by-90-degree/
// CodeStudio link: https://bit.ly/3rhVUWx
// Leetcode link: https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>
using namespace std;

int dir[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

pair<int,int> getNextIndex(int i,int j,int startX, int startY,int n, int m, int &curr_dir)
{
    int newX = i + dir[curr_dir][0];
    int newY = j + dir[curr_dir][1];

    if(newX >=startX && newX < n+startX && newY >=startY && newY < m+startY) 
        return {newX, newY};
    curr_dir = (curr_dir+1)%4;
    return {i+dir[curr_dir][0], j+dir[curr_dir][1]};
}
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = n, col = m;
    int startX=0, startY=0;

    while(n>1 && m>1) {
        int i=startX, j=startY;
        int prev = mat[i][j];
        int curr_dir = 0;
        do{
            pair<int,int> nextCoordinates = getNextIndex(i,j,startX,startY,n,m, curr_dir);
            i = nextCoordinates.first;
            j = nextCoordinates.second;
            swap(prev, mat[i][j]);
        } while(!(i == startX && j == startY));

        startX++, startY++;
        n-=2, m-=2;
    }
}
// int main() {
//     vector<vector<int>> mat = {{1 ,2, 3, 4},
// {5, 6, 7, 8},
// {9, 10, 11, 12},
// {13, 14, 15, 16}};
//     rotateMatrix(mat,4,4);
// }