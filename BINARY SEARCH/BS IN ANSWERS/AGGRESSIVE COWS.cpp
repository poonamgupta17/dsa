//to find the largest minimum distance between cows placed in stalls
//tc: O(nlogm) , m is the max distance between first and last stall , n is number of stalls
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool possibleDist(vector<int>& stalls,int dist,int cows){
        int cowsPlaced=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=dist){
                cowsPlaced+=1;
                last=stalls[i];
            }
            if(cowsPlaced>=cows)return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=0,high=(stalls[n-1]-stalls[0]);
        while(low<=high){
            int mid=(low+high)/2;
            bool possible=possibleDist(stalls,mid,k);
            if(possible==true)low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};