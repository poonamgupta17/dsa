//lc-300 longest increasing subsequence
//find the length of longest increasing subsequence in the given array

//recursive + memoization
//tc: O(n^2)
//sc: O(n^2) for dp array + O(n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[2501][2502];
    int solve(int i,int p,int n,vector<int>&nums){
        if(i>=n)return 0;
        if(t[i][p+1]!=-1)return t[i][p+1];
        //take
        int take=0;
        if(p==-1 || nums[p]<nums[i]){
            take=1+solve(i+1,i,n,nums);
        }
        //skip
        int skip=solve(i+1,p,n,nums);
        return t[i][p+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return solve(0,-1,n,nums);
    }
};
//bottom up
//tc: O(n^2)
//sc: O(n) for dp array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,1);
        int maxAns=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);
                    maxAns=max(t[i],maxAns);    
                }
            }
        }
        return maxAns;
    }
};