//lc-875
//to find the minimum eating speed to finish all bananas in h hours
//tc: O(nlogm) , m is max element in piles
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxHr(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>maxi){
                maxi=piles[i];
            }
        }
        return maxi;
    }
    long long calcHrs(vector<int>& piles,int hourly){
        int n=piles.size();
        long long total=0;
        for(int i=0;i<n;i++){
            total+=(piles[i]+hourly-1)/hourly;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=maxHr(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hr=calcHrs(piles,mid);
            if(hr<=h)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};