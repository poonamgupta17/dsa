//lc-74 search in a 2d matrix
//tc: O(log (n*m)) where n is number of rows and m is number of columns
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); //rows
        int n=matrix[0].size(); //cols
        int low=0;
        int high=(m*n)-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]<target)low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};