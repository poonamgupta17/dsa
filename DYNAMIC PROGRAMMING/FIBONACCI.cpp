//lc-509 fibonacci number

//recursive approach
//t.c: O(2^n)
//s.c: O(n) for recursive stack space
#include<bits/stdc++.h>
using namespace std;
class Solution {public:
    int fib(int n) {
        if(n<=1)return n;
        return fib(n-1)+fib(n-2);
    }
};

//recursive approach with memoization
//tc: O(n) 
//sc: O(n+1) for dp array and O(n) for recursive stack space

class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n) {
        if(n<=1)return n;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
//bottom up approach
//tc: O(n)
//sc: O(n+1) for dp array
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//space optimized approach
//tc: O(n)
//sc: O(1)
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        int a=0;
        int b=1;
        int c;
        for(int i=1;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};