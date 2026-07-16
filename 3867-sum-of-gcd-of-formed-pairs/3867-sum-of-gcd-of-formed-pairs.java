class Solution {
    long gcd(long a,long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    public long gcdSum(int[] nums) {
        int n = nums.length;

        long pre[] = new long[n];
        long max=0;
        for(int i=0;i<n;i++){

            max = Math.max((long)nums[i],max);
            pre[i] = gcd((long)nums[i], max);
        }

        Arrays.sort(pre);
        


        int i=0;int j=n-1;
        long ans = 0;
        while(i<j){
            ans +=gcd(pre[i],pre[j]);
            i++;
            j--;
        }


        return ans;


    }
}