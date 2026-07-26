//lc-309
//best time to buy and sell stock with cooldown, you cannot buy on the next day after you sell your stock (i.e., cooldown of one day).

//recursion+memoization
//tc=O(n*2)
//sc=O(n*2) + O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[5001][2];
    
    int solve(int i,bool buy,vector<int>& prices){
        if(i>=n)return 0;
        if(t[i][buy]!=-1)return t[i][buy];
        int profit=0;
        if(buy){
            //take= -prices[i] +solve(i+1,0,prices)
            //not take= 0+solve(i+1,1,prices)
            profit=max(-prices[i] +solve(i+1,0,prices),0+solve(i+1,1,prices)); 
        }   
        else{
            //sell
            profit=max(prices[i] +solve(i+2,1,prices),0+solve(i+1,0,prices)); 
        }  
        return t[i][buy]=profit;   
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        if(n==1){
            return 0;
        }
        memset(t,-1,sizeof(t));
        return solve(0,1,prices);
    }
};
//bottom up approach
//tc=O(n*2)
//sc=O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
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
                    dp[i][j]=max(prices[i] +dp[i+2][1],0+dp[i+1][0]); 
                }  
            }
            
        }
        return dp[0][1]; 
    }
};
//space optimized bottom up approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>curr(2);
        vector<int>prev1(2);
        vector<int>prev2(2);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    //take= -prices[i] +solve(i+1,0,prices)
                    //not take= 0+solve(i+1,1,prices)
                    curr[j]=max(-prices[i] +prev1[0],0+prev1[1]); 
                }   
                else{
                    //sell
                    curr[j]=max(prices[i] +prev2[1],0+prev1[0]); 
                }  
                prev2=prev1;
                prev1=curr;
            }
            
        }
        return curr[1]; 
    
    }
};