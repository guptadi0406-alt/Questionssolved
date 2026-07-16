class Solution {

    int MOD = (int)(1e9+7);

    int invmod = 500000004;
    public int numOfSubarrays(int[] arr) {

        long n = arr.length;
        long curr = 0;

        HashMap<Long,Long> hm = new HashMap<>();
        hm.put(0l,1l);

        long ans = 0;
        for(int i=0;i<n;i++){
            curr=((curr%2+arr[i]%2)+2)%2;
            ans = (ans %MOD + hm.getOrDefault(curr%2,0l)%MOD)%MOD;
            hm.put(curr%2,(hm.getOrDefault(curr%2,0l)%MOD+1%MOD)%MOD);
        }


        long il = ((n%MOD*(n+1)%MOD)+MOD)%MOD;
        long left = ((il%MOD * invmod%MOD)+MOD)%MOD;
        long right = ans % MOD;
 
        return (((int)left%MOD - (int)right%MOD)+MOD)%MOD;
        
    }
}