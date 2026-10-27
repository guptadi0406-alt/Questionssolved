class Solution {

bool check(long long mid,int x,long long k){

    long long sum=0;
    
    for(int j = x;j<=60;j+=x){

        if((1LL<<(j-1)) >mid) break;

        long long sz = (1LL<<(j));
        long long temp = mid/sz;
        long long ki = (temp*sz)/2;

        sum+=ki;
        ki = mid%sz;
        long long p = sz/2;

        if(ki>=p){
            sum+=(ki-p+1);
        }

        if(sum>k) return false;
     
    }

    return sum<=k;
}

public:
    long long findMaximumNumber(long long k, int x) {
        
        long long i = 1;
        long long j = 1e17;
        long long ans = 0;
        while(i<=j){
            long long mid = i+(j-i)/2;
            if(check(mid,x,k)){
                ans = mid;
                i=mid+1; 
            }else{
                j=mid-1;
            }
        }   

        return ans;
    }

};