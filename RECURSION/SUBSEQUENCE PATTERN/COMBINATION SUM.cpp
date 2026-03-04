//lc-39 to find all the combinations of the given array that sum up to the target(can use the same element multiple times)

//tc=O(2^t * k) where t is the target and k is the average length of the combinations because in the worst case we can have all the elements as 1 and we can use them t times to get the target
//sc=O(k*x)=hypothetical, where k is the average length of the combinations and x is the number of combinations because we are storing all the combinations in the ans vector
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findCombo(int i,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>&ds){
        if(i==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            findCombo(i,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
        //not pick
        findCombo(i+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombo(0,target,candidates,ans,ds);
        return ans;

    }
};