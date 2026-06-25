//lc-516

//using longest common subsequence approach
//tc: O(n^2)
//sc: O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string &s1, string &s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>t(n+1,vector<int>(m+1));
        
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
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        //string s2=reverse(s.begin(),s.end());
        return longestCommonSubsequence(s1,s);
    }
};
//recursive + memoization
//tc: O(n^2)
//sc: O(n^2) for dp array + O(n) for recursion stack
class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j, string &s){
        if(i>j)return 0;
        if(t[i][j]!=-1)return t[i][j];
        if(i==j)return t[i][j]= 1;
        if(s[i]==s[j]){
            return t[i][j]= 2+solve(i+1,j-1,s);
        }
        else{
            return t[i][j]=max(solve(i+1,j,s),solve(i,j-1,s));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n,s);
    }
};