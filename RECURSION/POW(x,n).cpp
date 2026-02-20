//lc-50 Pow(x,n) to calculate x raised to the power n

//conditions:
//1. -100.0 < x < 100.0
//2. n is a 32-bit signed integer, within the range [−231, 231 − 1]

//iterative solution using fast exponentiation
//tc: O(logn)
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1; 
        long long nn=n; //to handle the case when n is INT_MIN, as -INT_MIN is out of range for int
        if(nn<0)nn=-1*nn;
        while(nn){
            if(nn%2){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0)ans=(double)(1.0)/(double)(ans); //if n is negative, take the reciprocal of the result
        return ans;
    
    }
};