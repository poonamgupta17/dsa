//to count the number of subsequences with sum k
//time complexity: O(2^n)
//space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
int printS(int ind,int sum,int k,vector<int>& arr,int n){
        if(sum>k)return 0;//valid only if we have +ve numbers in array.
        if(ind==n){
            if(sum==k)return 1;
            else return 0;
        }
      
        sum+=arr[ind];
        int l=printS(ind+1,sum,k,arr,n);
    
        sum-=arr[ind];
        
        int r=printS(ind+1,sum,k,arr,n);
        return l+r;
    }
int main() {
     vector<int> arr={1,2,1};
        int k=2;
        int n=arr.size();
        cout<<"number of subsequences with sum ("<<k<<")= "<<printS(0,0,k,arr,n);
    return 0;
}