//lc-72 
//to find the minimum number of operations required to convert s1 to s2 (operations allowed: insert, remove, replace)

//recursive + memoization(forward indexing)
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

//recursive + memoization (backward indexing)
//tc: O(n*m)
//sc: O(n*m)+O(n+m)
class Solution {
public:
    int n,m;
    int t[501][501];
    int solve(int m,int n, string s1,string s2){
        if(m==0 || n==0){
            return m+n;
        }
        if(t[m][n]!=-1)return t[m][n];
        if(s1[m-1]==s2[n-1]){
            return solve(m-1,n-1,s1,s2);
        }
        else{
            int insert=1+solve(m,n-1,s1,s2);
            int remove=1+solve(m-1,n,s1,s2);
            int replace=1+solve(m-1,n-1,s1,s2);
            return t[m][n]= min({insert,remove,replace});
        }
    }
    int minDistance(string s1, string s2) {
        n=s1.length();
        m=s2.length();
        memset(t,-1,sizeof(t));
        return solve(n,m,s1,s2);
    }
};
//tabulation
//tc: O(n*m)
//sc: O(n*m)
class Solution {
public:
    int n,m;
    int t[501][501];
    int solve(int m,int n, string s1,string s2){
        if(m==0 || n==0){
            return m+n;
        }
        if(t[m][n]!=-1)return t[m][n];
        if(s1[m-1]==s2[n-1]){
            return solve(m-1,n-1,s1,s2);
        }
        else{
            int insert=1+solve(m,n-1,s1,s2);
            int remove=1+solve(m-1,n,s1,s2);
            int replace=1+solve(m-1,n-1,s1,s2);
            return t[m][n]= min({insert,remove,replace});
        }
    }
    int minDistance(string s1, string s2) {
        m=s1.length();
        n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]= i+j;
                }
                else if(s1[i-1]==s2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min({t[i-1][j],t[i][j-1],t[i-1][j-1]});
                }
            }
        }
        return t[m][n];
    }
};