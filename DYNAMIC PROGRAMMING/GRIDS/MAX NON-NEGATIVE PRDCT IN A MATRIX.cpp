//lc-1594
//return the maximum non-negative product from top left to bottom right in a m*n grid (allowing only right and down moves)

//recursive+memoization
//tc= O(m*n) for recursion + O(m*n) for dp table
//sc= O(m*n) for dp table + O(m+n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    typedef long long ll;
    vector<vector<pair<ll,ll>>>t;
    int mod=1e9+7;
    pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
        if(t[i][j].first!=LLONG_MIN)return t[i][j];
        if(i==m-1 && j==n-1)return t[i][j]={grid[i][j],grid[i][j]};
         
        ll maxval=LLONG_MIN;
        ll minval=LLONG_MAX;

        //down
        if(i+1<m){
            pair<ll,ll> down=solve(i+1,j,grid);
            maxval=max({maxval,grid[i][j]*down.first,grid[i][j]*down.second});
            minval=min({minval,grid[i][j]*down.first,grid[i][j]*down.second});
        } 
        //right
        if(j+1<n){
            pair<ll,ll> right=solve(i,j+1,grid);
            maxval=max({maxval,grid[i][j]*right.first,grid[i][j]*right.second});
            minval=min({minval,grid[i][j]*right.first,grid[i][j]*right.second});
        }
        return t[i][j]= {maxval,minval};
    
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        t=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
        auto res=solve(0,0,grid);
        return res.first <0 ? -1: res.first % mod;
    }
};

//bottom up 
//tc= O(m*n)
//sc= O(m*n)
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        typedef long long ll;
        int mod=1e9+7;
        vector<vector<pair<ll,ll>>>t(m,vector<pair<ll,ll>>(n));

        t[0][0]={grid[0][0],grid[0][0]};

        //first row
        for(int j=1;j<n;j++){
            t[0][j].first=grid[0][j]*t[0][j-1].first;
            t[0][j].second=grid[0][j]*t[0][j-1].second;
        }
        //first col
        for(int i=1;i<m;i++){
            t[i][0].first=grid[i][0]*t[i-1][0].first;
            t[i][0].second=grid[i][0]*t[i-1][0].second;
        }
        for (int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=t[i-1][j].first;
                ll upmin=t[i-1][j].second;
                ll leftmax=t[i][j-1].first;
                ll leftmin=t[i][j-1].second;
                
                t[i][j].first=max({grid[i][j]*upmax,grid[i][j]*upmin,grid[i][j]*leftmax,grid[i][j]*leftmin});
                t[i][j].second=min({grid[i][j]*upmax,grid[i][j]*upmin,grid[i][j]*leftmax,grid[i][j]*leftmin});
            }
        }
        ll maxPrd=t[m-1][n-1].first;
        
        return maxPrd<0 ? -1: maxPrd % mod;
    }
};
