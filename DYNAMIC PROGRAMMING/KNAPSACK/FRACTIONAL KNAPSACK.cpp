//fractional knapsack problem- we are given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In fractional knapsack, we can break items for maximizing the total value of knapsack.

//greedy approach- we can take the item with the highest value/weight ratio first, and then take the next item with the highest value/weight ratio, and so on, until we reach the capacity of the knapsack. If we reach an item that cannot be taken completely, we can take a fraction of it to fill the knapsack to its capacity.
//tc: O(nlogn) + O(n) = O(nlogn)
//sc: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={val[i],wt[i]};
        }
        auto lambda=[](pair<int,int>& p1, pair<int,int>&p2){ //here,[] is called the capture list. It tells the lambda whether it wants to use variables from outside.
            return (1.0 * p1.first/p1.second)>(1.0 * p2.first/p2.second);
        };
        sort(begin(vec),end(vec),lambda); //here,the comparator always puts the pair with the higher value/weight ratio first, which is exactly what the greedy fractional knapsack algorithm requires.
        double result=0.0;
        for(int i=0;i<n;i++){
            if(vec[i].second<=capacity){
                result+=vec[i].first;
                capacity-=vec[i].second;
            }
            else{
                result+=(1.0 * vec[i].first/vec[i].second)* capacity;
                break;
            }
        }
        return result;
    }
};
