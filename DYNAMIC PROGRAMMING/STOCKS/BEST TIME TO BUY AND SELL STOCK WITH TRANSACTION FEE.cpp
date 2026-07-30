//lc-714
//best time to buy and sell stock with transaction fee, you can make as many transactions as you like, but you need to pay the transaction fee for each complete transaction.

//recursion+memoization
//tc=O(n*2)
//sc=O(n*2) + O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[50001][2];
    int n;
    int solve(int i,int buy,int fee,vector<int>& prices){
        if(i==n)return 0;
        if(t[i][buy]!=-1)return t[i][buy] ;
        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(i+1,0,fee,prices),0+solve(i+1,1,fee,prices));
        }
        else{
            profit=max(prices[i]+solve(i+1,1,fee,prices)-fee,0+solve(i+1,0,fee,prices));
        }
        return t[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,fee,prices);
    }
};

//bottom up approach
//tc=O(n*2)
//sc=O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>t(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            t[i][1]=max(-prices[i]+t[i+1][0], 0+t[i+1][1]);

            t[i][0]=max(prices[i]+t[i+1][1]-fee, 0+t[i+1][0]);
        }
        return t[0][1];
    }
};

//space optimized bottom up approach
//tc=O(n*2)
//sc=O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>>t(n+1,vector<int>(2,0));
        vector<int>prev(2,0);
        vector<int>curr(2);
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]+prev[0], 0+prev[1]);

            curr[0]=max(prices[i]+prev[1]-fee, 0+prev[0]);
            prev=curr;
        }
        return curr[1];
    }
};