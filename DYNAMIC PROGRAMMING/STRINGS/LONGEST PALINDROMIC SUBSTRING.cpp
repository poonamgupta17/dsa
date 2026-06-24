//lc-5
// Given a string s, return the longest palindromic substring in s.

//brute force approach(recursive)
//tc=O(n^3)
//sc=O(n)(auxiliary space for recursion)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i, int j, string &s){
        if(i>j){
            return true;
        }
        if(s[i]==s[j]){
            return check(i+1,j-1,s);
        }
        else{
            return false;
        }
    }
    string longestPalindrome(string s) {
        int maxL=0;
        int n=s.length();
        int sp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    if(j-i+1>maxL){
                        maxL=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxL); //string substr(start, size); start → starting index size → number of characters to extract
    }
};
//recursive approach with memoization
//tc=O(n^2)
//sc=O(n^2)(auxiliary space for dp array)
class Solution {
public:
    int t[1001][1001];
    bool check(int i, int j, string &s){
        if(i>j){
            return true;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(s[i]==s[j]){
            return t[i][j]=check(i+1,j-1,s);
        }
        else{
            return t[i][j]= false;
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        int maxL=0;
        int sp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    if(j-i+1>maxL){
                        maxL=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxL);
    }
};
//bottom up dp approach(table filling)
//tc=O(n^2)
//sc=O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        int maxL=1;
        int sp=0;
        for(int l=1;l<=n;l++){
            for(int i=0;l+i-1<n;i++){
                int j=l+i-1;
                if(i==j){
                    t[i][j]=1;
                    maxL=1;
                    sp=i;
                }
                else if(i+1==j && s[i]==s[j]){
                    t[i][j]=1;
                    maxL=2;
                    sp=i;
                }
                else{
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                    if(t[i][j]){
                        if(l>maxL){
                            maxL=l;
                            sp=i;
                        }
                    }
                }
            }
        }
        return s.substr(sp,maxL);
    }
};