//lc-3363

//recursion+memoization
//tc=o(n^2) for recursion
//sc=o(n^2) for recursion stack
#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int n;
    int t[1001][1001];
    const int NEG = -1e9;
    int calcC1(vector<vector<int>>& fruits){
        int result=0;
        for(int i=0;i<n;i++){
            result+=fruits[i][i];
            fruits[i][i]=0;
        }
        return result;
    }
    int calcC2(int i,int j,vector<vector<int>>& fruits){
        
        if(i>=n || j>=n || j<0){
            return NEG;
        }
        if(i==n-1 && j==n-1)return 0;
        if(i>j ||i==j)return NEG;
        if(t[i][j]!=-1)return t[i][j];
        int bottomLeft=fruits[i][j]+calcC2(i+1,j-1,fruits);
        int bottom=fruits[i][j]+calcC2(i+1,j,fruits);
        int bottomRight=fruits[i][j]+calcC2(i+1,j+1,fruits);
        return t[i][j]= max({bottomLeft,bottom,bottomRight});
    }
    int calcC3(int i,int j,vector<vector<int>>& fruits){
        
        if(j>=n || i>=n || i<0){
            return NEG;
        }
        if(i==n-1 && j==n-1)return 0;
        if(i<j ||i==j)return NEG;
        if(t[i][j]!=-1)return t[i][j];
        int topRight=fruits[i][j]+calcC3(i-1,j+1,fruits);
        int right=fruits[i][j]+calcC3(i,j+1,fruits);
        int bottomRight=fruits[i][j]+calcC3(i+1,j+1,fruits);
        return t[i][j]= max({topRight,right,bottomRight});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        memset(t,-1,sizeof(t));
        int c1=calcC1(fruits);
        int c2=calcC2(0,n-1,fruits);
        memset(t,-1,sizeof(t));
        int c3=calcC3(n-1,0,fruits);
        return c1+c2+c3;
    }
};