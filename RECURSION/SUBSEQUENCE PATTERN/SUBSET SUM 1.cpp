//to find the sum of all the subsets of an array
#include <bits/stdc++.h>
using namespace std;

//brute force approach

//tc=O(n*2^n) where n is the number of elements in the array because we are generating all the subsets and for each subset we are calculating the sum which takes O(n) time
//sc=O(2^n) because we are storing all the subset sums in the ans vector and in the worst case we can have all the elements as 1 and we can use them n times to get the target
class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans;
        for(int num=0;num<(1<<n);num++){ //2^n=1<<n
            int sum=0;
            for(int i=0;i<n;i++){
                if(num & (1<<i)){
                    sum+=arr[i];
                }
            }
            ans.push_back(sum);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//optimal approach using recursion
//tc=O(2^n) where n is the number of elements in the array because we are generating all the subsets and for each subset we are calculating the sum which takes O(1) time
//sc=O(2^n) because we are storing all the subset sums in the ans vector and in the worst case we can have all the elements as 1 and we can use them n times to get the target
class Solution {
  public:
    void generateSum(int index,int sum,vector<int>&ans,vector<int>&arr){
        if(index==arr.size()){
            ans.push_back(sum);
            return;
        }
        generateSum(index+1,sum+arr[index],ans,arr);
        generateSum(index+1,sum,ans,arr);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        generateSum(0,0,ans,arr);
        return ans;
    }
};