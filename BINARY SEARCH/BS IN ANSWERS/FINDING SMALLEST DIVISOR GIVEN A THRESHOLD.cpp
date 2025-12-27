//lc-1283
//to find the smallest divisor such that the sum of the division of all elements is less than or equal to threshold
//tc: O(nlogm) , m is max element in nums,n is size of nums
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxHr(vector<int>& nums,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return maxi;
    }
    int div(vector<int>& nums,int threshold,int mid){
        int sum=0; 
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        if(sum>threshold)return 0;
        return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold) return 0;
        int low=1,high=maxHr(nums,n);
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=div(nums,threshold,mid);
            if(ans==0)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};