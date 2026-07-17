class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        
        int n = words.length;
        int pre[] = new int[n];

        for(int i=0;i<n;i++){
            int m = words[i].length();
            char a = words[i].charAt(0);
            char b = words[i].charAt(m-1);

            // System.out.printf("%c , %c \n",a,b);


            if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
                if(b=='a' || b=='e' || b=='i' || b=='o' || b=='u'){
                    pre[i]+=1;   
                }
            }
            if(i>0) pre[i]+=pre[i-1];

        }

        // System.out.println(Arrays.toString(pre));

        int k = queries.length;

        int ans[]=new int[k];
        for(int i=0;i<k;i++){
            int l = queries[i][0];
            int r = queries[i][1];

            if(l==0){
                ans[i]=pre[r];
            }else{
                ans[i]=pre[r]-pre[l-1];
            }
        }

        return ans ;





    }
}