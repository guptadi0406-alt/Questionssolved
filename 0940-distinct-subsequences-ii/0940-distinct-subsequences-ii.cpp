class Solution {
    int mod = 1e9+7;
public:
    int distinctSubseqII(string s) {
        int n = s.length();

        int dp[n+1];
        int last[26];
        int prefix[n+1];

        memset(last,-1,sizeof(last));

        dp[0]=1;
        prefix[0]=1;

        for(int i=1;i<=n;i++){
            dp[i] = prefix[i-1]%mod;

            if(last[s[i-1]-'a']!=-1){
                int index = last[s[i-1]-'a']%mod;
                dp[i] = ((dp[i]%mod-prefix[index-1]%mod)+mod)%mod;
            }
            last[s[i-1]-'a'] = i;
            prefix[i]=(prefix[i-1]%mod+dp[i]%mod)%mod;
        }

        return ((prefix[n]%mod-1%mod)+mod)%mod;
    }
};