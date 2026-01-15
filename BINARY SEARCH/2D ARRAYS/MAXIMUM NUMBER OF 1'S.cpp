//to find the maximum number of 1's from the row in a matrix and return the row number
//tc: O(n log m) n- number of rows, m- number of columns
//sc=O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int lowerBound(vector<int>& arr,int n, int target) {
        // code here
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();       // no of rows
        int m=arr[0].size();    //no of cols
        int index=-1;
        int max_cnt=0;
        for(int i=0;i<n;i++){
            int one_cnt=m-lowerBound(arr[i],m,1);
            if(one_cnt>max_cnt){
                max_cnt=one_cnt;
                index=i;
            }
        }
        return index;
    }
};