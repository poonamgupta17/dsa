//lc 1011
//to find the least weight capacity of a ship to ship all packages within D days
//tc: O(nlogm) , m is sum of all weights in weights,n is size of weights
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxWt(vector<int>& bloomDay){
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]>maxi){
                maxi=bloomDay[i];
            }
        }
        return maxi;
    }
    int summ(vector<int>& num){
        int sum=0;
        for(int i=0;i<num.size();i++){
            sum+=num[i];
        }
        return sum;
    }
    int possible(vector<int>& weights,int c,int days){
        int cnt=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>c){
                cnt+=1;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        if(cnt>days)return 0;
        else return 1;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int n=weights.size();
        int low=maxWt(weights),high=summ(weights);
        while(low<=high){
            int mid=low+(high-low)/2;
            int c=possible(weights,mid,D);
            if(c==0)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};