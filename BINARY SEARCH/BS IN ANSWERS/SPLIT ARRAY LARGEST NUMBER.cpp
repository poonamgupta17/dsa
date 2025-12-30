//LC-410
//to split the array into m subarrays such that the largest sum among these subarrays is minimized
//tc: O(nlogm) , m is the sum of all elements , n is
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxN(vector<int>& arr){
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        return maxi;
    }
    int summ(vector<int>& arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }
    int alct(vector<int>& arr, int pg,int k){
        int st=1;
        int pages=0;
        for(int i=0;i<arr.size();i++){
            if(pages+arr[i]<=pg){
                pages+=arr[i];
            }
            else{
                st+=1;
                pages=arr[i];
            }
        }
        return st;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size())return -1;
        int low=maxN(arr),high=summ(arr);
        while(low<=high){
            int mid=(low+high)/2;
            int ans=alct(arr,mid,k);
            if(ans>k)low=mid+1;
            else high=mid-1;
            
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
       return findPages(nums,k); 
    }
};