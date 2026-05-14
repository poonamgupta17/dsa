//to return the count of binary strings of length n without consecutive 1's
//time complexity: O(n)
//space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // #define ll long long
    long long countStrings(int n) { 
        // code here
        int oneend=1;
        int zeroend=1;
        int sum=oneend+zeroend;
        if(n==1)return sum;
        int i=2;
        while(i<=n){
            oneend=zeroend ;
            zeroend=sum ;
            sum=zeroend+oneend % (1000000007); //to avoid overflow we will take mod with 10^9+7
            i++;
        }
        return sum;
    }
};