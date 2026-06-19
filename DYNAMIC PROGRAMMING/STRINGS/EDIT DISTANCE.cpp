//lc-72 
//to find the minimum number of operations required to convert s1 to s2 (operations allowed: insert, remove, replace)

//recursive + memoization
//tc: O(n*m)
//sc: O(n*m)+O(n+m)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    int t[501][501];
    int solve(int i,int j, string s1,string s2){
        if(i==n){
            return m-j;
        }
        else if(j==m){
            return n-i;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(s1[i]==s2[j]){
            return solve(i+1,j+1,s1,s2);
        }
        else{
            int insert=1+solve(i,j+1,s1,s2);
            int remove=1+solve(i+1,j,s1,s2);
            int replace=1+solve(i+1,j+1,s1,s2);
            return t[i][j]= min({insert,remove,replace});
        }
    }
    int minDistance(string s1, string s2) {
        n=s1.length();
        m=s2.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,s1,s2);
    }
};