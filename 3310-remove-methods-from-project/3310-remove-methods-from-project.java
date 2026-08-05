class Solution {
    List<Integer> ans = new ArrayList<>();
    public void dfs1(int root,ArrayList<Integer> graph[],int visited[]){
        visited[root] = 1;


        for(int nbr : graph[root]){
            if(visited[nbr] == 0){
                dfs1(nbr,graph,visited);
            }
        }


    }
    boolean canremoved=true;
    public void dfs2(int root,ArrayList<Integer> graph[],int visited[],int mark[]){
        visited[root] = 1;

        if(mark[root]==1){
            canremoved=false;
        }

        for(int nbr : graph[root]){
            if(visited[nbr] == 0){
                dfs2(nbr,graph,visited,mark);
            }
        }


    }


    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        
        ArrayList<Integer> graph[] = new ArrayList[n];

        for(int i=0;i<n;i++){
            graph[i]=new ArrayList<>();
        }

        for(int i=0;i<invocations.length;i++){
            graph[invocations[i][0]].add(invocations[i][1]);
        }

        System.out.println(Arrays.toString(graph));

        int mark[]=new int[n];
        dfs1(k,graph,mark);


        System.out.println(Arrays.toString(mark));

        int visited[]=new int[n];

        for(int i=0;i<n;i++){
            if(mark[i]==0 && visited[i]==0){
                dfs2(i,graph,visited,mark);
            }
        }

        if(!canremoved){
            for(int i=0;i<n;i++){
                ans.add(i);
            }

        }else{
            for(int i=0;i<n;i++){
                if(mark[i]==0) ans.add(i);
            }
        }



        return ans;
    }
}