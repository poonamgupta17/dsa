//lc-198 house robber

//recursive + memoization
//tc: O(n)
//sc: O(n) for dp array and O(n) for recursive stack space
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[101];
    int solve(int i,int n,vector<int>&nums){
        if(i>=n)return 0;
        if(t[i]!=-1)return t[i];
        int steal=nums[i]+solve(i+2,n,nums);
        int skip=solve(i+1,n,nums);
        return t[i]= max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,nums);
    }
};
//bottom up approach
//tc: O(n)
//sc: O(n) for dp array
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+dp[i-2];
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n];
    }
};
//space optimized approach
//tc: O(n)
//sc: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        int prevprev=0;
        int prev=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+prevprev;
            int skip=prev;
            int temp=max(steal,skip);
            prevprev=prev;
            prev=temp;
        }
        return prev;
    }
};