//lc-121

//Greedy approach
//tc=O(n)
//sc=O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int min_left = prices[0];
        for(int i=1;i<n;i++){
            int cost = prices[i] - min_left;
            profit = max(profit,cost);
            min_left = min(prices[i],min_left);
        }
        return profit;
    }
};