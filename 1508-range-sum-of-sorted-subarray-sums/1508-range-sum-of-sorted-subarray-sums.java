class Solution {
    long MOD = (long)1e9+7;
    public int rangeSum(int[] nums, int n, int left, int right) {
        

        int len = (n*(n+1))/2;
        long sumarr[]=new long[len];
        int k=0;
        for(int i=0;i<n;i++){
            long curr = nums[i] %MOD;
            sumarr[k]=curr%MOD;
            k++;
            for(int j=i+1;j<n;j++){
                curr=(curr%MOD+nums[j]%MOD)%MOD;
                sumarr[k]=curr%MOD;
                k++;
            }
        }


        Arrays.sort(sumarr);

    //    System.out.println(Arrays.toString(sumarr));
    //    System.out.println(left);
    //    System.out.println(right);

        long ans = 0;
        for(int i=left-1;i<right;i++){
            ans = (ans %MOD + sumarr[i]%MOD)%MOD;
        }

        return (int)(ans%MOD);
    }
}