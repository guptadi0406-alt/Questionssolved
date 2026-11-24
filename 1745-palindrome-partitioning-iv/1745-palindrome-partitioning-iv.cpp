class Solution {

    int dp[20002][4];
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

    int rec(int i,int k,string &s){
        if(k<0) return 0;

        if(i==-1){
            if(k==0) return 1;
            return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];

        int ans = 0;
        for(int j=i;j>=0;j--){

            if(is_pal(j,i,s)){
                if(rec(j-1,k-1,s)){
                    ans = 1;
                }
            }

        }

        return dp[i][k]=ans ;
    }
public:
    bool checkPartitioning(string s) {
        int n = s.length()-1;
        memset(dp,-1,sizeof(dp));
        return rec(n,3,s);
    }
};