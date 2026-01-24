//to get the median of a row-wise sorted matrix
//tc: O(log(10)^9 * n log m) n- number of rows, m- number of columns (10^9 is the range of elements)
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int upperBound(vector<int>& arr, int target,int m) {
        
        int low=0;
        int high=m-1;
        int ans=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    int blackbox(vector<vector<int>> &mat, int target){
        int cnt=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            cnt+=upperBound(mat[i],target,m);    
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int required=(m*n)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smallEquals=blackbox(mat,mid);
            if(smallEquals<=required)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};

