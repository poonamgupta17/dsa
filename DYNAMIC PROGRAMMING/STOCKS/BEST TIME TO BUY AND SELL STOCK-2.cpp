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
    int profit;
    int solve(int i,bool buy,vector<int>& prices){
        if(i==n)return 0;
        if(t[i][buy]!=-1)return t[i][buy];
        if(buy){
            //take= -prices[i] +solve(i+1,0,prices
            //not take= 0+solve(i+1,1,prices
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