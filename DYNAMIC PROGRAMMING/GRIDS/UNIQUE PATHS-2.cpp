//lc-63 
//return the number of unique paths from top left to bottom right in a m*n grid (allowing only right and down moves) with obstacles

//recursive+memoization
//tc= O(m*n) for recursion + O(m*n) for dp table
//sc= O(m*n) for dp table + O(m+n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[101][101];
    int m,n;
    int solve(int i, int j, vector<vector<int>>&grid){
        
        if(i>=m || i<0 || j>=n ||j<0 ||grid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(t[i][j]!=-1)return t[i][j];
        int right=solve(i,j+1,grid);
        int down=solve(i+1,j,grid);
        return t[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};

//bottom-up
//tc= O(m*n) for dp table
//sc= O(m*n) for dp table
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            
            if(j>0 && grid[0][j-1]==1){
                t[0][j]=0;
                grid[0][j]=1;
            }
            else if(grid[0][j]==1)t[0][j]=0;
            else{
                t[0][j]=1;
            }
        }
        for(int i=0;i<m;i++){ //0th col
            
            if(i>0 && grid[i-1][0]==1){
                t[i][0]=0;
                grid[i][0]=1;
            }
            else if(grid[i][0]==1)t[i][0]=0;
            else{
                t[i][0]=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1)t[i][j]=0;
                else t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};