// CodeStudio link: https://bit.ly/3Gv1Th5
// Leetcode link: https://leetcode.com/problems/flood-fill/
#include<bits/stdc++.h>
using namespace std;

void dfs (vector<vector<int>> &image, int x, int y, int newColor, int matchingColor)
{   
    int n = image.size();
    int m = image[0].size();
    if(x<0 || x>=n || y<0 || y>=m || image[x][y] == newColor || image[x][y] != matchingColor) return;
    
        image[x][y] = newColor;
        dfs(image, x-1, y, newColor, matchingColor);
        dfs(image, x+1, y, newColor, matchingColor);
        dfs(image, x, y-1, newColor, matchingColor);
        dfs(image, x, y+1, newColor, matchingColor);
    

}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int matchingColor = image[x][y];
    dfs(image,x,y,newColor, matchingColor);
    return image;
}