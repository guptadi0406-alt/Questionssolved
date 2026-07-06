class Comp implements Comparator<int[]>{

    @Override
    public int compare(int []a,int []b){
        if(a[0]==b[0]){
            return b[1]-a[1];
        }

        return a[0]-b[0];
    }
}

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals,new Comp());


        // System.out.println(Arrays.deepToString(intervals));

        int n = intervals.length;
        int mark[]=new int[n];

        for(int i=0;i<n;i++){
            if(mark[i]==0){
                for(int j=i+1;j<n;j++){
                        if(intervals[j][1]<=intervals[i][1]){
                            mark[j]=1;
                        }
                    
                }

            }
        }

        int ans =0;

        for(int i=0;i<n;i++){
            if(mark[i]==0) ans++;
        }
        

        // System.out.println(Arrays.toString(mark));


        return ans;
    }
}