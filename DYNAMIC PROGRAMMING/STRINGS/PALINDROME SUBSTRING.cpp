//lc-647

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

//brute force approach(TLE)
//tc=O(n^3)
//sc=O(n)(auxiliary space for recursion)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i,int j, string s){
        if(i>j){
            return true;
        }
        if(s[i]==s[j]){
            return check(i+1,j-1,s);
        }
        return false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};
//recursive approach with memoization
//tc=O(n^2)
//sc=O(n^2)(auxiliary space for dp array)
class Solution {
public:
    int t[1001][1001];
    bool check(int i,int j, string &s){
        if(i>=j){
            return true;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(s[i]==s[j]){
            return t[i][j]= check(i+1,j-1,s);
        }
        return t[i][j]= false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        if(n==1)return n;
        int count=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};
//bottom up dp approach
//tc=O(n^2)
//sc=O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        int count=0;
        for(int l=1;l<=n;l++){
            for(int i=0;l+i-1<n;i++){
                int j=l+i-1;
                if(i==j){
                    t[i][j]=true;
                }
                else if(i+1==j){
                    t[i][j]=(s[i]==s[j]);   
                }
                else{
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                }
                if(t[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
//expanding from mid points approach
//tc=O(n^2)
//sc=O(1)
class Solution {
public:
    int count;
    int check(int i,int j,string &s,int n){
        while((i>=0 && j<n)&&s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int a,b;
        count = 0;
        for(int i=0;i<n;i++){
            check(i,i,s,n);
            check(i,i+1,s,n);
        }
        return count;
    }
};