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
//bottom up approach
//tc= O(n*W)
//sc= O(n*W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>t(n+1,vector<int>(W+1));
        //t[i][j]=max profit at item=i with weight=j
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        for(int j=0;j<W+1;j++){
            t[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                int take=0;
                int skip=0;
                if(wt[i-1]<=j){
                    take=val[i-1]+t[i-1][j-wt[i-1]];
                }
                skip=t[i-1][j];
                t[i][j]=max(take,skip);
            }
        }
        return t[n][W];
    }
};
//space optimized bottom up approach
//tc= O(n*W)
//sc= O(W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>curr(W+1,0);
        vector<int>prev(W+1,0);
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                int take=0;
                int skip=0;
                if(wt[i-1]<=j){
                    take=val[i-1]+prev[j-wt[i-1]]; //t[i-1]=prev, 
                }
                skip=prev[j];
                curr[j]=max(take,skip);
            }
            //move current row->prev row
            prev=curr;
        }
        return prev[W];
    }
};