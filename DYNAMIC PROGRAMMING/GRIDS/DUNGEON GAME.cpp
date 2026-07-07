//lc-174

//return the minimum initial health required to reach the princess in a m*n grid (allowing only right and down moves), where each cell has a health value (negative for damage, positive for health gain)

//brute force(recursion+binary search)(TLE)
//tc= O(2^(m+n)) for recursion
//sc= O(m+n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    bool canSurv(int i,int j,int mid,vector<vector<int>>& dungeon){
        if(i>=m || j>=n){
            return false;
        }
        mid+=dungeon[i][j];
        if(mid<=0)return false;

        if(i==m-1 && j==n-1)return true;
        return canSurv(i,j+1,mid,dungeon) || canSurv(i+1,j,mid,dungeon);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        int left=1;
        int right=4 * 1e7;
       
        int minHealth=4*1e7;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canSurv(0,0,mid,dungeon)){
                minHealth=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return minHealth;
    }
}; 
//recursion+memoization
//tc= O(m*n) for recursion
//sc= O(m*n) for recursion stack
class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(int i, int j,vector<vector<int>>& dungeon ){
        if(i>=m || j>=n)return INT_MAX;
        if(t[i][j]!=-1)return t[i][j];
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0)return 1;
            else{
                return abs(dungeon[i][j])+1;
            }
        }
        int down=solve(i+1,j,dungeon);
        int right=solve(i,j+1,dungeon);
        int res=min(down,right)-dungeon[i][j];
        return t[i][j]= res<=0 ? 1:res;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size(); 
        memset(t,-1,sizeof(t));
        return solve(0,0,dungeon);
    }
};
