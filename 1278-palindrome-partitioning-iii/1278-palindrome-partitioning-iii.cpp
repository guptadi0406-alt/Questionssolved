class Solution {
    vector<vector<int>> dp;

    int cost(int i,int j,string &s){

        int x = i;
        int y = j;
        int ans = 0;
        while(x<=y){
            if(s[x]!=s[y]) ans ++;
            x++;
            y--;
        }
        return ans;
    }   

    int rec(int i,int k,string &s){

        if(k<0) return 1e9;

        if(i==-1){
            return k==0 ? 0 : 1e9;
        }

        if (dp[i][k]!=-1) return  dp[i][k];

        int ans = 1e9;

        for(int j=i;j>=0;j--){
                ans = min(ans , cost(j,i,s) + rec(j-1,k-1,s));
         
        }
        return dp[i][k] = ans ;
    }
public:
    int palindromePartition(string s, int k) {
            int n = s.length();
            dp.assign(n+1,vector<int>(k+1,-1));

           
            return rec(n-1,k,s);
    }
};