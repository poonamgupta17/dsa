//to find nth root of m using binary search
//tc=log m*log n
class Solution {
  public:
    long long fl(long long j,int k,int m){
        long long ans=1;
        while(k>0){
            if(k%2==1){
                ans=ans*j;
                if(ans>m)return m+1;
                k=k-1;
            }
            else{
                k=k/2;
                j=j*j;
                if(j>m)return m+1;
            }
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here
        if(m==0)return 0;
        
        int low=1, high=m;
        while(low<=high){
            long long mid=(low+high)/2;
            long long e=fl(mid,n,m);
            if(e==m)return mid;
            if(e<=m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};