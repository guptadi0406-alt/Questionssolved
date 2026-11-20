class Solution {
    int dp[1010][1010];
    int n;int m;
    int rec(int i,int j,string &word1, string &word2){

        if(i>=n || j >=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans = max(rec(i+1,j,word1,word2) , rec(i,j+1,word1,word2));

        if(word1[i]==word2[j]){
            ans = max(ans,1+rec(i+1,j+1,word1,word2));
        }

        return dp[i][j] = ans;
    }

public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        
        n = word1.length();
        m = word2.length();

        int ans = rec(0,0,word1,word2);

        return (n-ans)+(m-ans);

    }
};