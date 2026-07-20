//0-1 knapsack problem- we are given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In 0-1 knapsack, we cannot break items, we either take the complete item or do not take it (0-1 property).

//recursion + memoization 

//forward indexing
//tc: O(n*W)
//sc: O(n*W)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int n;
    int t[1001][1001];
    int solve(int i,int w,vector<int> &val, vector<int> &wt){
        if(i>=n || w==0)return 0;
        if(t[i][w]!=-1)return t[i][w];
        int take=0;
        int skip=0;
        if(wt[i]<=w){
            take=val[i]+ solve(i+1,w-wt[i],val,wt);
        }
        
        skip=solve(i+1,w,val,wt);
        
        return t[i][w]=max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n=val.size();
        memset(t,-1,sizeof(t));
        return solve(0,W,val,wt);
    }
};
//backward indexing
//tc: O(n*W)
//sc: O(n*W)
class Solution {
  public:
    int n;
    int t[1001][1001];
    int solve(int n,int w,vector<int> &val, vector<int> &wt){
        if(n<=0 || w==0)return 0;
        if(t[n][w]!=-1)return t[n][w];
        int take=0;
        int skip=0;
        if(wt[n-1]<=w){
            take=val[n-1]+ solve(n-1,w-wt[n-1],val,wt);
        }
        
        skip=solve(n-1,w,val,wt);
        
        return t[n][w]=max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n=val.size();
        memset(t,-1,sizeof(t));
        return solve(n,W,val,wt);
    }
};