//to find the length of the shortest common supersequence of two strings 

//recursive + memoization approach(with forward indexing)
//tc: O(n*m) 
//sc: O(n*m) + O(n+m) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int t[501][501];
    int solve(string &s1,string &s2, int i, int j){
        if(i>=s1.length() || j>=s2.length()){
            return s1.length()+s2.length()-i-j;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(s1[i]==s2[j]){
            return t[i][j]= 1+solve(s1,s2,i+1,j+1);
        }
        else{
            return t[i][j]= 1+min(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
        }
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
};
//recursive + memoization approach(with reverse indexing)
class Solution {
  public:
    int t[501][501];
    int solve(string &s1,string &s2, int m, int n){
        if(m==0 || n==0){
            return m+n;
        }
        if(t[m][n]!=-1)return t[m][n];
        if(s1[m-1]==s2[n-1]){
            return t[m][n]= 1+solve(s1,s2,m-1,n-1);
        }
        else{
            return t[m][n]= 1+min(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
        }
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int m=s1.length();
        int n=s2.length();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,m,n);
    }
};

//bottom up approach
//tc: O(n*m)
//sc: O(n*m)
class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]= i+j;
                }
                else if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};