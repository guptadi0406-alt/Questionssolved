class Solution {
    public long sumAndMultiply(int n) {
        
        String s = String.valueOf(n);

  

        int m = s.length();
        String x = "";
        long sum = 0;
        for(int i=0;i<m;i++){
            int  a = s.charAt(i)-'0';

            if(a!=0){
                x+=s.charAt(i);
                sum+=a;
            }
        }



        if(x=="") return 0;
        long ans = Long.valueOf(x)*sum;

        return ans;
    }
}