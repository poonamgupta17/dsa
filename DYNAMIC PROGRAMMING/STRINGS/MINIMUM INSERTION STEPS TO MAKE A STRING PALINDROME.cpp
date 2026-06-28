//lc-1312

//recursive + memoization
//tc= O(n^2)
//sc= O(n^2) for dp array + O(n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[501][501];
    int solve(int i,int j, string &s1){
        if(i>j){
            return 0;  
        }
        if(t[i][j]!=-1)return t[i][j];
        if(s1[i]==s1[j]){
            return t[i][j]=solve(i+1,j-1,s1);
        }
        else{
            int insert=1+solve(i,j-1,s1);
            int insert2=1+solve(i+1,j,s1);
            return t[i][j]= min(insert,insert2);
        }
    }
    int minInsertions(string s) {
        memset(t,-1,sizeof(t));
        int n=s.length();
        return solve(0,n-1,s);
    }
};
