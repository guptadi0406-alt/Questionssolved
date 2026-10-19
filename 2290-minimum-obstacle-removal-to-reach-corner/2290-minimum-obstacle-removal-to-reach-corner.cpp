class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};

        deque<pair<int,int>> dq;
        dq.push_front({0,0});

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        vector<vector<int>> vis(n,vector<int>(m,0));
        dist[0][0]=0;

        while(!dq.empty()){
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            if(vis[x][y]) continue;
            vis[x][y]=1;

            for(int d=0;d<4;d++){

                int nr = x+dr[d];
                int nc = y+dc[d];

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int w=0;
                    if(grid[nr][nc]) w=1;

                    if(!vis[nr][nc] && dist[nr][nc]>dist[x][y]+w){
                        dist[nr][nc]=dist[x][y]+w;

                        if(w==0) {
                            dq.push_front({nr,nc});
                        }else{
                            dq.push_back({nr,nc});
                        }
                    }
                }
            }

        }

        return dist[n-1][m-1];
    }
};