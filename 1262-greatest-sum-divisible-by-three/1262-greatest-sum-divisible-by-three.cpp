class Solution {
    vector<vector<int>> dp;
    int rec(int i ,int l,vector<int>& nums){

        if(i<0){
            return l==0 ? 0 : -1e9;
        }

        if(dp[i][l]!=-1) return dp[i][l];

        int ans = -1e9;

        ans = max( ans , nums[i]+rec(i-1,(l+nums[i])%3,nums));
        ans = max( ans , rec(i-1,l,nums) );

        return dp[i][l] = ans;
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int  n = nums.size();
        dp.assign(n+1,vector<int>(4,-1));
        int ans =  rec(n-1,0,nums) ;
        return ans == -1e9 ? 0 : ans ;
    }   
};