class Solution {

    vector<vector<pair<int,int>>> graph;
    vector<vector<int>> dp;

    int d;

    int rec(int city,int k){


        if(k<0) return 1e9;
        if(city == d){
            return 0;
        }

        if(dp[city][k]!=-1) return dp[city][k];
        int ans = 1e9;

        ans = min(ans , rec(city,k-1));

        for(auto [nbr,w] : graph[city]){
            ans = min(ans , rec(nbr,k-1) + w);
        }

        return dp[city][k] = ans ;

    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        graph.assign(n,vector<pair<int,int>>());
        dp.assign(n+1,vector<int>(k+2,-1));
        d = dst;
        for(int i=0;i<flights.size();i++){

            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            graph[u].push_back({v,w});
        }


        int ans = rec(src,k+1) ;
        return ans == 1e9 ? -1 : ans ;

    }
};