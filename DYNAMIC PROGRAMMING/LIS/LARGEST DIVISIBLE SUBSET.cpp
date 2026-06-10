//lc-368

//recursive + memoization (time limit exceeded)
//tc: O(2^n) 
//sc: O(n) for recursion stack + O(n) for temp array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>& result,vector<int>& temp,int prev){
        if(idx>=nums.size()){
            if(temp.size()>result.size()){
                result=temp;
            }
            return;
        }
        //take
        if(prev==-1 || nums[idx] % prev==0){
            temp.push_back(nums[idx]);
            solve(idx+1,nums,result,temp,nums[idx]);
            temp.pop_back();
        }
        //not take
        solve(idx+1,nums,result,temp,prev);
    
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        vector<int>result;
        vector<int>temp;
        solve(0,nums,result,temp,-1);
        return result;
    }
};
//bottom up
//tc: O(n^2)
//sc: O(n) for dp array
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        vector<int>subset(n,1);
        vector<int>prev_idx(n,-1);

        int maxL=1;
        int last_chosen_idx=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(subset[i]<subset[j]+1){
                        subset[i]=subset[j]+1;
                        prev_idx[i]=j;
                    }
                    if(subset[i]>maxL){
                        maxL=subset[i];
                        last_chosen_idx=i;
                    }
                }
            }
        }
        vector<int>result;
        while(last_chosen_idx!=-1){
            result.push_back(nums[last_chosen_idx]);
            last_chosen_idx=prev_idx[last_chosen_idx];
        }
        return result;
    }
};