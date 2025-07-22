//to check if an array is sorted and rotated

#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&arr){
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            count++;
        }
    }
    return count<=1;
}
int main(){
    vector<int>arr={5,6,7,8,9,10,1,2,3,4};
    if(check(arr)){
        cout<<"Array is sorted and Roated"<<endl;
    }else{
        cout<<"Array is not sorted and Roated"<<endl;
    }
    return 0;
}
