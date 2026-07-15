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
//bottom up
//tc=o(n^2)
//sc=o(n^2)
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        vector<vector<int>>t(n,vector<int>(n));
        //for 1st child
        int result=0;
        for(int i=0;i<n;i++){
            result+=fruits[i][i];
        }
        //before c2 and c3, nullify other cells that can't be used
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j && i+j<n-1)t[i][j]=0;
                else if(i>j && i+j<n-1)t[i][j]=0;
                else{
                    t[i][j]=fruits[i][j];
                }
            }
        }
        //for c2
        for(int i=1;i<n;i++){
            for (int j=i+1;j<n;j++){
                t[i][j]+=max({t[i-1][j-1],t[i-1][j],(j+1<n)?t[i-1][j+1]:0});
            }
        }
        //for c3
        for(int j=1;j<n;j++){
            for (int i=j+1;i<n;i++){
                t[i][j]+=max({t[i-1][j-1],t[i][j-1],(i+1<n)?t[i+1][j-1]:0});
            }
        }
        return result+t[n-2][n-1]+t[n-1][n-2];
    }
};