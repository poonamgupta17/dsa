//lc-2926 
//find the maximum sum of balanced subsequence in the given array
//a subsequence is balanced if for every element in the subsequence, the difference between the element and its index is greater than or equal to the difference between any previous element in the subsequence and its index

//recursive + memoization(this will give tle)
//tc= O(n^2) in worst case (when all elements are same)
//sc= O(n^2) for memoization + O(n) for recursion stack  
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string, long long> mp; //For memoization
    long long solve(int i, int prev, vector<int>& nums) {
        if(i >= nums.size()) {
            return 0;
        }

        string key = to_string(i) + "_" + to_string(prev);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long taken = INT_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev) {
            taken = nums[i] + solve(i+1, i, nums);
        }
        
        long long not_taken = solve(i+1, prev, nums);
        return mp[key] = max<long long>(taken, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }
        return solve(0, -1, nums);
    }
};

//bottom up(this will give tle as well)
//tc= O(n^2) 
//sc= O(n) 
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }

        vector<long long> t(n);
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }
            }
        }
        return maxSum > maxEl ? maxSum : maxEl;
    }
};
