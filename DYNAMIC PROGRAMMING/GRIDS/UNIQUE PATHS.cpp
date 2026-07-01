//lc-62 
//return the number of unique paths from top left to bottom right in a m*n grid (allowing only right and down moves)

//recursive+memoization
//tc= O(m*n) for recursion + O(m*n) for dp table
//sc= O(m*n) for dp table + O(m+n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[101][101];
    int solve(int i,int j,int m, int n){
        if(t[i][j]!=-1)return t[i][j];
        if(i>=m || i<0 || j>=n || j<0){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        int right=solve(i,j+1,m,n);
        int down=solve(i+1,j,m,n);
        return t[i][j]=right+down;

    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n);
    }
};
//bottom-up
//tc= O(m*n) for dp table
//sc= O(m*n) for dp table
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>t(m,vector<int>(n));
        //t[i][j] = number of unique paths to reach cell (i,j) from (0,0)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)t[i][j]=1;
                else{
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }
        return t[m-1][n-1];
    }
};