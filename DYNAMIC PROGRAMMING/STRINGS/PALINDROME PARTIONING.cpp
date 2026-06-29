//lc-131

//recursive
//tc= O(n^2*2^n)( isPalindrome() scans every time + substr()-->	n² × 2^n )
//sc= O(n) for recursion stack + O(n) for curr vector
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;    
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    void check(string &s,int idx,vector<string>curr, vector<vector<string>> &result){
        if(idx==n){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                check(s,i+1,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        n=s.length();
        vector<string>curr;
        check(s,0,curr,result);
        return result;
    }
};

//blueprint(by filling the dp table)
//tc= O(n*2^n) for recursion + O(n^2) for dp table ( substr() copies strings --> n × 2^n )
// "Copy = ×n, Scan = ×n. If both happen repeatedly during backtracking, answer becomes ×n²."
//sc= O(n^2) for dp table + O(n) for recursion stack
class Solution {
public:
    void solve(int i,string &s,vector<string>&curr,vector<vector<string>> &result,vector<vector<int>>&t){
        if(i==s.length()){
            result.push_back(curr);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(t[i][j]==1){
                curr.push_back(s.substr(i,j-i+1));
                solve(j+1,s,curr,result,t);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<int>>t(n,vector<int>(n));
        for(int l=1;l<=n;l++){
            for(int i=0;l+i-1<n;i++){
                int j=l+i-1;
                if(i==j)t[i][j]=1;
                else if(s[i]==s[j]){
                    if(l==2){
                        t[i][j]=1;
                    }
                    else{
                        t[i][j]=t[i+1][j-1];
                    }      
                }
            }
        }
        vector<string>curr;
        vector<vector<string>>result;
        solve(0,s,curr,result,t);
        return result;
    }
};