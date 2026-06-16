//lc-1143

//bottom up(forward indexing)
//tc: O(n*m)
//sc: O(n*m) for dp array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>t(n+1,vector<int>(m+1));//Create n+1 rows, where each row is a vector of size m+1.(a matrix initialized as 0)
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]= 1+t[i-1][j-1];
                }
                else{
                t[i][j]= max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        //for printing the longest common subsequence
        string lcs="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j]>t[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(begin(lcs),end(lcs)); //since we are traversing from the end of the strings, we need to reverse the lcs string before printing it.
        cout<<lcs<<endl;
        return t[n][m];
        
    }
};
//bottom up(reverse indexing)
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // Reconstruct the LCS string
        string lcs = "";
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                lcs.push_back(s1[i]);
                i++;
                j++;
            } else {
                if (dp[i + 1][j] >= dp[i][j + 1]) {
                    i++;
                } else {
                    j++;
                }
            }
        }

        cout << lcs << endl;

        return dp[0][0];
    }
};