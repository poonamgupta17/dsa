//lc-122

//recursion+memoization
//tc=O(n)
//sc=O(n) 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[30001][2];
    
    int solve(int i,bool buy,vector<int>& prices){
        if(i==n)return 0;
        if(t[i][buy]!=-1)return t[i][buy];
        int profit=0;
        if(buy){
            //take= -prices[i] +solve(i+1,0,prices)
            //not take= 0+solve(i+1,1,prices)
            profit=max(-prices[i] +solve(i+1,0,prices),0+solve(i+1,1,prices)); 
        }   
        else{
            //sell
            profit=max(prices[i] +solve(i+1,1,prices),0+solve(i+1,0,prices)); 
        }  
        return t[i][buy]=profit;   
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,prices);
    }
};
//bottom up approach
//tc=O(n)
//sc=O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    //take= -prices[i] +solve(i+1,0,prices)
                    //not take= 0+solve(i+1,1,prices)
                    dp[i][j]=max(-prices[i] +dp[i+1][0],0+dp[i+1][1]); 
                }   
                else{
                    //sell
                    dp[i][j]=max(prices[i] +dp[i+1][1],0+dp[i+1][0]); 
                }  
            }
            
        }
        return dp[0][1];
    }
};

//space optimized bottom up approach
//tc=O(n)
//sc=O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>curr(2);
        vector<int>prev(2,0);
        curr[0]=curr[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    //take= -prices[i] +solve(i+1,0,prices
                    //not take= 0+solve(i+1,1,prices
                    curr[j]=max(-prices[i] +prev[0],0+prev[1]); 
                }   
                else{
                    //sell
                    curr[j]=max(prices[i] +prev[1],0+prev[0]); 
                } 
                prev=curr; 
            }  
        }
        return curr[1];
    }
};