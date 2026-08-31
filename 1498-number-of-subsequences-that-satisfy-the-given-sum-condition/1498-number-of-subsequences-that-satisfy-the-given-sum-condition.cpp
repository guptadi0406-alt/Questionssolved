class Solution {

    int MOD = 1e9+7;
    long long power(int a ,int b){
        if(b==0) return 1;

        long long half = power(a,b/2)%MOD;
        long long  ans = (half%MOD*half%MOD)%MOD;

        if(b%2!=0){
            ans = (ans%MOD * a %MOD)%MOD;
        }
        return ans%MOD;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int i=0;int j=n-1;
    
        int ans = 0;
        while(i<=j){

            if(nums[i]+nums[j]<=target){
                ans = (ans%MOD + (power(2,j-i))%MOD)%MOD;
                i++;
            }else{
                j--;
            }
        }



        return ans % MOD;
    }
};