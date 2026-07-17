class Solution {
    public int bestClosingTime(String customers) {
        
        int n = customers.length();

        int ty=0;

        for(int i=0;i<n;i++){
            char a = customers.charAt(i);
            if(a=='Y'){
                ty+=1;
            }
        }

        int noy=0;
        int nono=0;
        int ans = Integer.MAX_VALUE;
        int minind = -1;
        for(int i=0;i<n;i++){

            int penelty = ty - noy + nono;
            char a = customers.charAt(i);

            if(a=='Y'){
                noy++;
            }else{
                nono++;
            }

            if(penelty<ans){
                minind=i;
                ans = penelty;
            }
        
        }

        if(nono<ans){
            minind=n;
        }


        return minind;

    }
}