class Solution {

    bool check(int n ,int m ,int mid,int k){
        int a = 0;
        for(int i=1;i<=n;i++){
            a += min(m,mid/i);
        }
        return a>=k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        
        int i=1;int j=m*n;
        int ans =-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(check(n,m,mid,k)){
                ans = mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }

        return ans;
    }
};