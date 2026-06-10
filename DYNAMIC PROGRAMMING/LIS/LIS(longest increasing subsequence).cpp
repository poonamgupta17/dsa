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
//optimal by lower_bound(patience sorting)
//(lower_bound is used to find the position of element just greater than or equal to the given element in sorted array and we are maintaining a sorted array of increasing subsequence
//we are replacing the element in sorted array with the current element if it is just greater than or equal to the current element)

//tc= O(nlogn)
//sc= O(n) for dp array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        for(int i=0;i<n;i++){
            auto it=lower_bound(begin(sorted),end(sorted),nums[i]); //nums[i] just greater than or equal to i
            if(it==end(sorted)){
                sorted.push_back(nums[i]); //greater number so add it 
            }
            else{
                *it=nums[i]; //replace the element in sorted array with the current element if it is just greater than or equal to the current element
            }
        }
        return int(sorted.size());
    }
};
