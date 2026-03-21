//lc-40 to find all the unique combinations of the given array that sum up to the target(can use the same element once)

//tc=O(2^n * k) where n is the number of elements in the array and k is the average length of the combinations because in the worst case we can have all the elements as 1 and we can use them n times to get the target
//sc=O(k*x)=hypothetical, where k is the average length of the combinations and x is the number of combinations because we are storing all the combinations in the ans vector
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findCombo(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
            
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            findCombo(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        findCombo(0,target,candidates,ans,ds);
        return ans;

    }
};