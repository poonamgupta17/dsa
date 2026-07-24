//frog jump problem
//to find the minimum energy to reach the last stone from the first stone, by moving either 1 or 2 steps at a time

//recursive + memoization
//tc: O(n)
//sc: O(n) for dp array and O(n) for recursive stack space
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int n;
    int t[100001];
    int solve(int i,vector<int>& height){
        if(i==n-1)return 0;
        if(t[i]!=-1)return t[i];
        int one=INT_MAX;
        int two=INT_MAX;
        if(i+1<n){
            one=solve(i+1,height)+ abs(height[i]-height[i+1]);
        }
        if(i+2<n){
            two=solve(i+2,height)+abs(height[i]-height[i+2]);    
        }
        
        return t[i]= min(one,two);
    }
    int minCost(vector<int>& height) {
        // Code here
        n=height.size();
        memset(t,-1,sizeof(t));
        return solve(0,height);
    }
};