//to check if there is a subset with sum equal to given sum

//recursion + memoization
//tc: O(n * sum), sc: O(n * sum)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int t[201][20001];
    bool solve(int n,int sum,vector<int>& arr){
        if(sum==0)return true;
        if(n==0)return false;
        
        if(t[n][sum]!=-1)return t[n][sum];
        int skip=solve(n-1,sum,arr);
        int take=false;
        if(sum>=arr[n-1]){
            take=solve(n-1,sum-arr[n-1],arr);
        }
        return t[n][sum]= take || skip;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(n,sum,arr);
    }
};
//bottom up
//tc: O(n * sum), sc: O(n * sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>t(n+1,vector<int>(sum+1,false));
        //t[i][j]=is it possible to get subset sum j having i number of elements
        for(int i=0;i<n+1;i++){
            t[i][0]=true; //at sum=0, its always possible, just skip all
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                bool skip=t[i-1][j];
                bool take=false;
                if(arr[i-1]<=j){
                    take=t[i-1][j-arr[i-1]];
                }
                t[i][j]=take || skip;
            }
        }
        return t[n][sum];
    }
};
//space optimized bottom up
//tc: O(n * sum), sc: O(sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<int>curr(sum+1,false);
        vector<int>prev(sum+1,false);
        
        prev[0]=true;
        curr[0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                bool skip=prev[j];
                bool take=false;
                if(arr[i-1]<=j){
                    take=prev[j-arr[i-1]];
                }
                curr[j]=take || skip;
            }
            prev=curr;
        }
        return curr[sum];
    }
};