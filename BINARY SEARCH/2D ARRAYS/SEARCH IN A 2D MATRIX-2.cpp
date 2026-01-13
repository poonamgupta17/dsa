//lc-240 search a 2d matrix II
//tc: O(m+n) where m is number of rows and n is number of columns   
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row=0,col=n-1;
        while(row<m && col>=0){
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]<target)row++;
            else col--;
        }
        return false;
    }
};