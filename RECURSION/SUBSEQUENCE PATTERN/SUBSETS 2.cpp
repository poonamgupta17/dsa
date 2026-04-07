//lc-90  to find all the subsets of a given set of numbers, which may contain duplicates, and return the solution in sorted order. The solution set must not contain duplicate subsets. 
//tc=O(2^n * n)
//sc=O(2^n * k) where k is the average length of the subsets because we are storing all the subsets in the ans vector and in the worst case we can have all the elements as 1 and we can use them n times to get the target
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findSubset(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            findSubset(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findSubset(0,nums,ds,ans);
        return ans;
    }
};