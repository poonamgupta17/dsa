//lc-22 generate parentheses
//tc=O(4^n/sqrt(n)) as we are generating all the possible combinations of valid parentheses and there are 4^n/sqrt(n) such combinations(catalan number)
//sc=O(n) due to recursion stack space used in generate function
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(vector<string> &ans,int n,int open,int close,string curr_str){
        if(curr_str.size()==n*2){
            ans.push_back(curr_str);
            return;
        }
        if(open<n)generate(ans,n,open+1,close,curr_str+"(");
        if(close<open)generate(ans,n,open,close+1,curr_str+")");

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans,n,0,0,"");
        return ans;
    }
};