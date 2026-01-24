//lc-1901
//PEAK ELEMENT IN 2D MATRIX (matrix having no two adjacent cells equal)
//tc: O(n log m) n- number of rows, m- number of columns
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat,int n,int m, int col){
        int maxEl=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxEl){
                maxEl=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int index=findMaxIndex(mat,n,m,mid);
            int left=mid-1>0 ? mat[index][mid-1]:-1;
            int right=mid+1<m ? mat[index][mid+1]:-1;
            if(left<mat[index][mid] && mat[index][mid]>right)return {index,mid};
            else if(left>mat[index][mid])high=mid-1;
            else low=mid+1;
        }
        return{-1,-1};
    }
};