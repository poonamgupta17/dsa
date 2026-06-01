//lc-213
//similar to house robber but here we have to consider the first and last element as adjacent as the houses are in a circle
//so we have two cases either we can consider the first element and skip the last element or we can skip the first element and consider the last element

//recursive + memoization
//tc: O(n)
//sc: O(n) 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[101];
    int solve(int i,int n,vector<int>&nums){
        if(i>n)return 0; //not using i>=n because we are passing n-2 and n-1 as the last index in the two cases not the size of the array
        if(t[i]!=-1)return t[i];
        int steal=nums[i]+solve(i+2,n,nums);
        int skip=solve(i+1,n,nums);
        return t[i]= max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        //case 1: consider the first house and skip the last house
        memset(t,-1,sizeof(t));
        int solve_for_0th=solve(0,n-2,nums);

        //case 2: skip the first house and consider the last house
        memset(t,-1,sizeof(t));
        int solve_for_1st=solve(1,n-1,nums);

        return max(solve_for_0th,solve_for_1st);
    }
};