//lc-70 climbing stairs

// recursive approach with memoization
//tc: O(2^n)
//sc: O(n) for dp array and O(n) for recursive stack space
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int one_step=solve(n-1,dp);
        int two_step=solve(n-2,dp);
        return dp[n]=one_step+two_step;
    }
    int climbStairs(int n) {
        vector<int>dp(46,-1);
        return solve(n,dp);
    }
};
//bottom up approach
//tc: O(n)  
//sc: O(n) for dp array
class Solution {
public: 
    int climbStairs(int n) {
        vector<int>dp(46,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};