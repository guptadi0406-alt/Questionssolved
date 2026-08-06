class Solution {
    public int smallestNumber(int n, int k) {
        
        while(true){

            int t = n;
            int prod = 1;
            while(t>0){
                    prod*=(t%10);
                    t/=10;
            }

            if(prod%k==0){
                return n;
            }

            n++;
        }
        
    }
}