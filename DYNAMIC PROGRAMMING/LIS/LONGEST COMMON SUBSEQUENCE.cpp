//lc-1143

//recursive + memoization
//tc: O(n*m)
//sc: O(n*m) for dp array + O(n+m) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    int t[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        if(i>=n || j>=m){
            return 0;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(s1[i]==s2[j]){
            return 1+solve(s1,s2,i+1,j+1);
        }
        return t[i][j]= max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    int longestCommonSubsequence(string s1, string s2) {
        n=s1.length();
        m=s2.length();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
};

//bottom up
//tc: O(n*m)
//sc: O(n*m) for dp array
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>t(n+1,vector<int>(m+1));//Create n+1 rows, where each row is a vector of size m+1.(a matrix initialized as 0)
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]= 1+t[i-1][j-1];
                }
                else{
                t[i][j]= max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
        
    }
};