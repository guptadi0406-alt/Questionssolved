

class Solution {
    int edge=0;
    int dfs1(int node,ArrayList<Integer> graph[],int vis[]){
        vis[node]=1;
        int c=1;
            edge+=(graph[node].size());
        for(int nbr:graph[node]){
                if(vis[nbr]==0){
                
                    c+=dfs1(nbr,graph,vis);
                }

        }

        return c;
    }


    public int countCompleteComponents(int n, int[][] edges) {
        ArrayList<Integer> graph[] =  new ArrayList[n];

        for(int i=0;i<n;i++){
            graph[i]= new ArrayList<>();
        }

        int m =edges.length;

        for(int i=0;i<m;i++){
            int u =edges[i][0];
            int v =edges[i][1];

            graph[u].add(v);
            graph[v].add(u);

        }

        int vis[] =new int[n];

        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                edge=0;
                int c = dfs1(i,graph,vis);
                int degree = edge/2;

                int q = (c*(c-1))/2;

                if(q==degree){
                    ans++;
                }
              
            }
        }


        return ans;

    }
}