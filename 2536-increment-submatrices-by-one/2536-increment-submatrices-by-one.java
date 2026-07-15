class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
   
        int m =queries.length;
        int ans [][]=new int[n][n];

        for(int i=0;i<m;i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for(int j=r1;j<=r2;j++){
                ans[j][c1]+=1;
            }

            if(c2+1<n){
                for(int j=r1;j<=r2;j++){
                    ans[j][c2+1]-=1;
                }

            }
            
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                if(j-1>=0) ans[i][j]+=ans[i][j-1];
            }
        }



        return ans;

    }
}