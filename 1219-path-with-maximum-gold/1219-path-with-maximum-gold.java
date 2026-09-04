class Solution {
    int dr[] ={-1,1,0,0};
    int dc[] ={0,0,1,-1};
    int n ;int m;

    int rec(int i,int j , int [][] grid){

        int x = grid[i][j];
        grid[i][j]=0;

        int ans = x;

        for(int d=0;d<4;d++){

            int nr = i+dr[d];
            int nc = j+dc[d];

            if(nr<n && nc<m && nr>=0 && nc>=0 && grid[nr][nc]!=0){
                ans = Math.max(ans,x+rec(nr,nc,grid));
            }

        }
        grid[i][j]=x;
       
        return ans ;
    }
    public int getMaximumGold(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                   ans=Math.max(ans,rec(i,j,grid));
                }
            }
        }

        return ans ;    


    }
}