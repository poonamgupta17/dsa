//lc-188
//best time to buy and sell stock where at most k transactions are allowed

//recursion+memoization
//tc=O(n*2*k)
//sc=O(n*2*k) + O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[1001][201];
    int solve(int i,int trans,int k,vector<int>& prices){
        if(trans==2*k || i==n)return 0;
        if(t[i][trans]!=-1)return t[i][trans];
        int profit=0;
        if(trans%2==0){ //buy
            profit= max(-prices[i]+solve(i+1,trans+1,k,prices),0+solve(i+1,trans,k,prices));
        }
        else{ //sell
            profit=max(prices[i]+solve(i+1,trans+1,k,prices),0+solve(i+1,trans,k,prices));
        }
        return t[i][trans]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,k,prices);
    }
};

//bottom up approach
//tc=O(n*2*k)
//sc=O(n*2*k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int trans=0;trans<=2*k-1;trans++){
                if(trans%2==0){ //buy
                    dp[i][trans]= max(-prices[i]+dp[i+1][trans+1],0+dp[i+1][trans]);
                }
                else{ //sell
                    dp[i][trans]=max(prices[i]+dp[i+1][trans+1],0+dp[i+1][trans]);
                }
            }
        }
        return dp[0][0];
    }
};

//space optimized bottom up approach
//tc=O(n*2*k)
//sc=O(2*k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>curr(2*k+1);
        vector<int>prev(2*k+1);
        for(int i=n-1;i>=0;i--){
            for(int trans=0;trans<=2*k-1;trans++){
                if(trans%2==0){ //buy
                    curr[trans]= max(-prices[i]+prev[trans+1],0+prev[trans]);//dp[i]=curr,dp[i+1]=prev
                }
                else{ //sell
                    curr[trans]=max(prices[i]+prev[trans+1],0+prev[trans]);
                }
                prev=curr;
            }
        }
        return curr[0];
    }
};