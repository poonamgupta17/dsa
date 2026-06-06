//lc-1420 
//given n,m,k find the number of arrays of size n with elements from 1 to m where you can find the maximum element exactly k comparisons

//recursive + memoization
//tc: O(n*m*m*k) n=size of array, m=maximum element, k=search cost
//sc: O(n*m*k) for dp array + O(n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[51][101][51];
    int N,M,K;  
    int mod=1e9+7;
    int solve(int idx,int maxSoFar,int cost){
        if(idx==N){
            if(cost==K)return 1;
            return 0;
        }
        if(t[idx][maxSoFar][cost]!=-1)return t[idx][maxSoFar][cost];
        int result =0;
        for(int i=1;i<=M;i++){
            if(i>maxSoFar){
                result=(result+solve(idx+1,i,cost+1))% mod;
            }
            else{
                result=(result+solve(idx+1,maxSoFar,cost))% mod;
            } 
        }
        return t[idx][maxSoFar][cost]=result % mod ;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};