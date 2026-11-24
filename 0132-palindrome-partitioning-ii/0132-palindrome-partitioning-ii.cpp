class Solution {
    int dp[20002];
    bool is_pal(int i,int j,string &s){
        
        int x=i;
        int y=j;

        while(x<=y){
            if(s[x]!=s[y]) return false;
            y--;
            x++;
        }
        return true;
    }

    int rec(int i,string &s){

        if(i==-1){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        int ans = 1e9;

        for(int j=i;j>=0;j--){
            if( is_pal(j,i,s) == 1 ){
                ans = min(ans,rec(j-1,s)+1);
            }
        }

        return dp[i] = ans ;
    }
public:
    int minCut(string s) {

        int n = s.length()-1;
        memset(dp,-1,sizeof(dp));

        return rec(n,s)-1;
    }
};