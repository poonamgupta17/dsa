// to print the subsequence(can skip elements, not continuous) whose sum is k
// for example arr={1,2,1} and k=2 then the output will be 1 1 and 2
// time complexity is O(2^n) because we are generating all the subsequences and checking their sum
// space complexity is O(n) because we are using a vector to store the subsequence and the maximum size of the vector can be n
#include <bits/stdc++.h>
using namespace std;
void printS(int ind,vector<int> &ds,int sum,int k,vector<int>& arr,int n){
        
        if(ind==n){
            if(sum==k){
                for(auto it:ds)cout<<it<<" ";
                cout<<endl;
            }
            return;
        }
        ds.push_back(arr[ind]);
        sum+=arr[ind];
        printS(ind+1,ds,sum,k,arr,n);
        
        ds.pop_back();
        sum-=arr[ind];
        printS(ind+1,ds,sum,k,arr,n);
    }
int main() {
     vector<int> arr={1,2,1};
        int k=2;
        int n=arr.size();
        vector<int> ds;
        printS(0,ds,0,k,arr,n);
    return 0;
}