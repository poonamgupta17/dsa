//lc-647

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

//brute force approach
//tc=O(n^3)
//sc=O(n)(auxiliary space for recursion)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i,int j, string s){
        if(i>j){
            return true;
        }
        if(s[i]==s[j]){
            return check(i+1,j-1,s);
        }
        return false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};