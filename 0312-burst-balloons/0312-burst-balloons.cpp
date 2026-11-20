class Solution {

public:
    int n ;
    vector<vector<int>> dp;
    int rec(int l,int r,vector<int>& nums){

        if(l>r){
            return 0;
        }

        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 0;

        for(int x=l;x<=r;x++){
            int left = 1;int right = 1;
            
            if(l-1>=0){
                left=nums[l-1];
            }
            if(r+1<n){
                right = nums[r+1];
            }

            ans = max(ans , rec(l,x-1,nums) + rec(x+1,r,nums) + nums[x]*right*left);
        }

        return dp[l][r] = ans ;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return rec(0,n-1,nums);
    }
};