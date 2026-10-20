class Solution {

    void dfs(int node,vector<vector<int>> &graph,vector<int> &vis){
        vis[node]=1;

        for(auto nbr:graph[node]){
            if(!vis[nbr]){
                dfs(nbr,graph,vis);
            }
        }
    }

    int spf[100100];

    void precompute(){
        for(int i=0;i<=100000;i++){
            spf[i]=i;
        }   

        for(int i=2;i<=100000;i++){
            if(spf[i]==i){
                for(int j=2*i;j<=100000;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        precompute();



        int maxn = 0;
        vector<int> primefactor[n];
        for(int i=0;i<n;i++){
            int t = nums[i];

            while(t>1){
                primefactor[i].push_back(spf[t]);
                t/=spf[t];
            }
        }

        map<int,int> mp;
        vector<vector<int>> graph(n);


        for(int i=0;i<n;i++){
        
            for(auto v : primefactor[i]){
                if(mp.find(v)!=mp.end()){
                    int node1 = i;
                    int node2 = mp[v];
                    graph[node1].push_back(node2);
                    graph[node2].push_back(node1);
                }
                mp[v]=i;
            }



        }


        vector<int> vis(n,0);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis);
                comp++;
            }
        }



        return comp>1 ? false : true;
    }   
};