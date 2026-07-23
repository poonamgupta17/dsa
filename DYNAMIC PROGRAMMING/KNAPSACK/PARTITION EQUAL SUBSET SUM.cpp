//lc-416 
//to check if the array can be partitioned into two subsets with equal sum, we can check if there is a subset with sum equal to total_sum/2,if total_sum is even, else return false
//as total_sum/2 is the sum of one subset, the other subset will also have sum total_sum/2, so we can partition the array into two subsets with equal sum

//tc: O(n * sum), sc: O(n * sum)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<int>curr(sum+1,false);
        vector<int>prev(sum+1,false);
        
        prev[0]=true;
        curr[0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                bool skip=prev[j];
                bool take=false;
                if(arr[i-1]<=j){
                    take=prev[j-arr[i-1]];
                }
                curr[j]=take || skip;
            }
            prev=curr;
        }
        return curr[sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 !=0)return false;
        return isSubsetSum(nums,sum/2);
    }
};