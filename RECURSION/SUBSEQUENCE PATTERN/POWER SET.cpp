//to find all the possible subsequences of a string 
//tc=O(n*2^n) as we are generating all the possible combinations of characters and there are 2^n such combinations and for each combination we are iterating through the string to check which characters are included in the combination
//sc=O(n) due to recursion stack space used in generate function
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        int n=s.size();
        vector<string> ans;
        for(int num=1;num<(1<<n);num++){ //2^n=1<<n
            string sub="";
            for(int i=0;i<n;i++){
                if(num & (1<<i))sub+=s[i];
            }
        ans.push_back(sub);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};