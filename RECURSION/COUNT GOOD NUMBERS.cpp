//lc-1922 count good numbers which are of length n and follow the rules:
//1. each character at an even index (0-indexed) is an even digit (0, 2, 4, 6, 8)
//2. each character at an odd index is a prime digit (2, 3, 5, or 7)

//tc: O(logn) due to fast exponentiation
//sc: O(logn) due to recursion stack space used in fast exponentiation

class Solution {
public:
    long long power(long long x,long long y,int mod){
        if(y==0)return 1;
        long long ans=power(x,y/2,mod);
        ans=ans*ans;
        ans=ans%mod;
        if(y%2)ans=ans*x;
        ans=ans%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        int mod=(1e9)+7;
        long long even=n/2+n%2;
        long long odd=n/2;
        return (power(5,even,mod)*power(4,odd,mod))%mod;
    }
};