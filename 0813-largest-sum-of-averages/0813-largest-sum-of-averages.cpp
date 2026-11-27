class Solution {

    int n;
    vector<vector<double>> dp;

    double rec(int i,int k,vector<int>& nums ){
        if(k<0) return -1e9;

        if(i < 0){
            return 0.0;
        }

        if(dp[i][k]!=-1.0) return dp[i][k];

        double ans = -1e9;
        double sum = 0;
        double elem = 0;
        for(int j=i;j>=0;j--){
            elem++;
            sum+=nums[j];
            ans = max(ans , rec(j-1,k-1,nums)+ (sum/elem));
        }

        return dp[i][k]=ans ;
    }   
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        n = nums.size();
        dp.assign(n+1,vector<double>(k+1,-1.0));
        

        return rec(n-1,k,nums) ;
    }
};