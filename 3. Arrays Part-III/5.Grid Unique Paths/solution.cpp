// Solution link: https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/
// CodeStudio link: https://bit.ly/3fm1dyN
// Leetcode link: https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h> 
using namespace std;
int uniquePaths(int m, int n) {
    
    int N = n+m-2;
    int downPaths = m-1;

    double uniquePath = 1;

    for(int i=1; i<m; i++) {
        uniquePath = uniquePath * (N - downPaths +i)/i;
    }
    return uniquePath;
}

int main() {
    cout<<uniquePaths(2,2);
}
