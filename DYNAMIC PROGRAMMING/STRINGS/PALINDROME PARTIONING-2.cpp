//lc-132

//recursive+memoization (time limit exceeded)
//tc= O(n^3) for recursion + O(n^2) for dp table 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[2001][2001];
    int solve(string &s,int i, int j,vector<vector<int>>&t){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t[i][j]==1)return dp[i][j]=0;
        
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int cut=1+solve(s,i,k,t)+solve(s,k+1,j,t);
            mini=min(cut,mini);
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
       int n=s.length();
       memset(dp,-1,sizeof(dp));
        vector<vector<int>>t(n,vector<int>(n));
        for(int l=1;l<=n;l++){
            for(int i=0;l+i-1<n;i++){
                int j=l+i-1;
                if(i==j)t[i][j]=1;
                else if(s[i]==s[j]){
                    if(l==2){
                        t[i][j]=1;
                    }
                    else{
                        t[i][j]=t[i+1][j-1];
                    }      
                }
            }
        } 
        return solve(s,0,n-1,t);
    }
};
//bottom-up
//tc=o(n^2) for dp table + O(n^2) for dp table
class Solution {
public:
    int n;
    int minCut(string s) {
        n=s.length();
        vector<vector<int>>t(n,vector<int>(n));
        for(int l=1;l<=n;l++){
            for(int i=0;l+i-1<n;i++){
                int j=l+i-1;
                if(i==j)t[i][j]=1;
                else if(s[i]==s[j]){
                    if(l==2){
                        t[i][j]=1;
                    }
                    else{
                        t[i][j]=t[i+1][j-1];
                    }      
                }
            }
        }
        vector<int>dp(n);
        //dp[i]=min cuts to split a string s[0...i] into palindrome
        for(int i=0;i<n;i++){
            if(t[0][i])dp[i]=0; //no cuts required
            else{
                dp[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(t[k+1][i]==1 && 1+dp[k]<dp[i]){
                        dp[i]=dp[k]+1;
                    }
                }
            }          
        }
    return dp[n-1];
    }
};