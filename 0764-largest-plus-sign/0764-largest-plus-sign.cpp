class Solution {
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int z;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    int rec(int i,int j,int dir){

        if(i<0 || j<0 || i>=z || j>=z) return 0;

        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        
        int ans = 0;
        if(grid[i][j]==1){
            ans = max(ans , 1+rec(i+dr[dir],j+dc[dir],dir));
        }

        return dp[i][j][dir] = ans ;
    }


public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        grid.assign(n,vector<int>(n,1));
        dp.assign(n,vector<vector<int>>(n,vector<int>(4,-1)));

        z=n;

        int m = mines.size();

        for(int i=0;i<m;i++){
            grid[mines[i][0]][mines[i][1]]=0;
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a =1e9;
                for(int d=0;d<4;d++){
                    a = min(a,rec(i,j,d));
                }
                ans = max(ans,a);
            }
        }

        return ans ;


    }
};