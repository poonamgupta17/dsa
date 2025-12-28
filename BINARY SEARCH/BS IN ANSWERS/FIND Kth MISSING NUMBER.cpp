//lc-1539
//to find the kth missing positive number from an array

//brute force approach
//tc: O(n)
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k)k++;
            else break;
        }
        return k;
    }
};

//optimal approach using binary search
//tc: O(logn)   
//sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k)low=mid+1;
            else high=mid-1;
        }
        return low+k;
    }
};