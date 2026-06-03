//lc-1911 
//find the maximum alternating subsequence sum(sum of elements at even indices - sum of elements at odd indices) in the given array

//recursive + memoization
//tc: O(n)
//sc: O(n) for recursion stack + O(n) for dp array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    long long t[100001][2];
    ll solve(int i,int n,vector<int>& nums,bool flag){
        if(i>=n)return 0;
        if(t[i][flag]!=-1)return t[i][flag];
        ll skip=solve(i+1,n,nums,flag);
        ll val=nums[i];
        if(flag==false){
            val=-val;
        }
        ll take=val+solve(i+1,n,nums,!flag);
        return t[i][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,nums,true);
    }
};
//bottom up
//tc: O(n)
//sc: O(n) for dp array
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>t(n+1,vector<long long>(2,0));
        for(int i=1;i<n+1;i++){
            t[i][0]=max(t[i-1][1]-nums[i-1],t[i-1][0]);
            t[i][1]=max(t[i-1][0]+nums[i-1],t[i-1][1]);
        }
        return max(t[n][0],t[n][1]);
    }
};