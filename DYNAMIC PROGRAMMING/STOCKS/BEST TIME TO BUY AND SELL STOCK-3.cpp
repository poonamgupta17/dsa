//lc- 123
//best time to buy and sell stock where at most 2 transactions are allowed

//recursion+memoization
//tc=O(n*2*3)
//sc=O(n*2*3) + O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[100001][2][3];
    
    int solve(int i,bool buy,int cap,vector<int>& prices){
        if(i==n ||cap==0)return 0;
        
        if(t[i][buy][cap]!=-1)return t[i][buy][cap];
        int profit=0;
        if(buy){
            //take= -prices[i] +solve(i+1,0,prices)
            //not take= 0+solve(i+1,1,prices)
            profit=max(-prices[i] +solve(i+1,0,cap,prices),0+solve(i+1,1,cap,prices)); 
        }   
        else{
            //sell
            profit=max(prices[i] +solve(i+1,1,cap-1,prices),0+solve(i+1,0,cap,prices)); 
        }  
        return t[i][buy][cap]=profit;   
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,2,prices);
    }
};
//bottom up approach
//tc=O(n*2*3)
//sc=O(n*2*3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // for(int i=0;i<n+1;i++){
        //     for(int buy=0;buy<=1;buy++){
        //         dp[i][buy][0]=0;
        //     }
        // }
        // for(int buy=0;buy<=1;buy++){
        //     for(int cap=0;cap<=2;cap++){
        //         dp[n][buy][cap]=0;
        //     }
        // }
        //no need for above loops as by default the entire table is 0 only
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        //take= -prices[i] +solve(i+1,0,prices)
                        //not take= 0+solve(i+1,1,prices)
                        dp[i][buy][cap]=max(-prices[i] +dp[i+1][0][cap],0+dp[i+1][1][cap]); 
                        }   
                    else{
                        //sell
                        dp[i][buy][cap]=max(prices[i] +dp[i+1][1][cap-1],0+dp[i+1][0][cap]); 
                    }  
                }                
            }
        }
        return dp[0][1][2];
    }
};
//space optimized bottom up approach
//tc=O(n*2*3)
//sc=O(2*3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>prev(2,vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        //take= -prices[i] +solve(i+1,0,prices)
                        //not take= 0+solve(i+1,1,prices)
                        curr[buy][cap]=max(-prices[i] +prev[0][cap],0+prev[1][cap]); 
                        }   
                    else{
                        //sell
                        curr[buy][cap]=max(prices[i] +prev[1][cap-1],0+prev[0][cap]); 
                    } 
                    prev=curr; 
                }                
            }
        }
        return curr[1][2];
    }
};


//recursion+memoization using only 2D array instead of 3D array
//tc=O(n*4)
//sc=O(n*4) + O(n)
class Solution {
public:
    int n;
    int t[100001][5];
    int solve(int i,int trans,vector<int>& prices){
        if(trans==4 || i==n)return 0;
        if(t[i][trans]!=-1)return t[i][trans];
        int profit=0;
        if(trans%2==0){ //buy
            profit= max(-prices[i]+solve(i+1,trans+1,prices),0+solve(i+1,trans,prices));
        }
        else{ //sell
            profit=max(prices[i]+solve(i+1,trans+1,prices),0+solve(i+1,trans,prices));
        }
        return t[i][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,prices);
    }
};
//bottom up approach using only 2D array instead of 3D array
//tc=O(n*4)
//sc=O(n*4)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int i=n-1;i>=0;i--){
            for(int trans=0;trans<=3;trans++){
                if(trans%2==0){ //buy
                    dp[i][trans]= max(-prices[i]+dp[i+1][trans+1],0+dp[i+1][trans]);
                }
                else{ //sell
                    dp[i][trans]=max(prices[i]+dp[i+1][trans+1],0+dp[i+1][trans]);
                }
            }
        }
        return dp[0][0]; //What is the maximum profit starting from day 0 when no transactions have been performed yet?"

    }
};
//space optimized bottom up approach using only 2D array instead of 3D array
//tc=O(n*4)
//sc=O(4)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>curr(5);
        vector<int>prev(5);
        for(int i=n-1;i>=0;i--){
            for(int trans=0;trans<=3;trans++){
                if(trans%2==0){ //buy
                    curr[trans]= max(-prices[i]+prev[trans+1],0+prev[trans]);//dp[i]=curr,dp[i+1]=prev
                }
                else{ //sell
                    curr[trans]=max(prices[i]+prev[trans+1],0+prev[trans]);
                }
                prev=curr;
            }
        }
        return curr[0]; //now, curr=dp[0] and curr[0]=dp[0][0]=What is the maximum profit starting from day 0 when no transactions have been performed yet?"
    }
};