//lc-216
//tc=O(k^n) as we are generating all the possible combinations of k numbers that sum up to n and there can be at most k^n such combinations
//sc=O(n) due to recursion stack space used in generate function
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void check(int i,int sum,int k,int n,vector<int>& ds,vector<vector<int>>& ans){
        if(k==0){
            if(sum==n){
                ans.push_back(ds);
            }
            return ;
        }
        if(sum>n || i>9)return ;
        //pick
        ds.push_back(i);
        check(i+1,sum+i,k-1,n,ds,ans);
        ds.pop_back();
        //not pick
        check(i+1,sum,k,n,ds,ans);
         
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        check(1,0,k,n,ds,ans);
    
        return ans;
    }
};