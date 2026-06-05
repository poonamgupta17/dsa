//lc-646
//find the length of longest chain of pairs in the given array of pairs

//recursive + memoization
//tc: O(n^2)
//sc: O(n^2) for dp array + O(n) for recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[2501][2502];
    int solve(int i,int p,int n,vector<vector<int>>& pairs){
        if(i>=n)return 0;
        if(t[i][p+1]!=-1)return t[i][p+1];
        //take
        int take=0;
        if(p==-1 || pairs[p][1]<pairs[i][0]){
            take=1+solve(i+1,i,n,pairs);
        }
        //skip
        int skip=solve(i+1,p,n,pairs);
        return t[i][p+1]=max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t,-1,sizeof(t));
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,n,pairs);
    }
};
//bottom up
//tc: O(n^2)
//sc: O(n) for dp array
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>t(n,1);
        int maxAns=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    t[i]=max(t[i],t[j]+1);
                    maxAns=max(t[i],maxAns);    
                }
            }
        }
        return maxAns;        
    }
};