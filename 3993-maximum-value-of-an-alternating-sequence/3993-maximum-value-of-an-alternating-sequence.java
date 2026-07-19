class Solution {
    public long maximumValue(int n, int s, int m) {
        
            if (n==1) return s;
            long len = n%2==0 ? (long)(n-1) : (long)(n-2) ;
            long max=s;
   
            long q = ((len+1)/2)*m - (len/2);
            //System.out.println((len+1)/2);
            long ans = s+q;
            return ans;
       


    }
}