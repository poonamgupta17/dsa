//lc-1482
//to find the minimum number of days to make m bouquets, each bouquet consists of k adjacent flowers
//tc: O(nlogm) , m is max element in bloomDay
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxHr(vector<int>& bloomDay,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>maxi){
                maxi=bloomDay[i];
            }
        }
        return maxi;
    }
    int minHr(vector<int>& bloomDay,int n){
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<mini){
                mini=bloomDay[i];
            }
        }
        return mini;
    }
    int poss(vector<int>& bloomDay,int dayno,int m,int k,int n){
        int cnt=0;
        int boq=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=dayno)cnt++;
            else{
                boq+=cnt/k;
                cnt=0;
            }
        }
        boq+=cnt/k;
        if(boq>=m)return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        long long size=(long long)m*k;
        if((size)>n)return -1;
        int low=minHr(bloomDay,n), high=maxHr(bloomDay,n);
        while(low<=high){
            int mid=low+(high-low)/2;
            int day=poss(bloomDay,mid,m,k,n);
            if(day==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};