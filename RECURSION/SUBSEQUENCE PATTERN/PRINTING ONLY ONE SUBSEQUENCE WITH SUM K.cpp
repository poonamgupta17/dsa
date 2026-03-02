//to print only one subsequence with sum k
//time complexity: O(2^n) because we are generating all the subsequences and checking their sum
//space complexity: O(n) because we are using a vector to store the subsequence and the maximum size of the vector can be n
#include <bits/stdc++.h>
using namespace std;
bool printS(int ind, vector<int> &ds, int sum, int k, vector<int>& arr, int n){
        
    if(ind == n){
        if(sum == k){
            for(auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    sum += arr[ind];
    if(printS(ind+1, ds, sum, k, arr, n))
        return true;

    ds.pop_back();
    sum -= arr[ind];
    if(printS(ind+1, ds, sum, k, arr, n))
        return true;

    return false;
}