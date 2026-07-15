class Solution {
    public int minSubarray(int[] nums, int p) {

            int n = nums.length;
            int sum=0;
            for(int i=0;i<n;i++){
                sum=(sum%p+nums[i]%p)%p;
            }

            int x = sum%p;

            if(x==0) return 0;
            int curr = 0;
            HashMap<Integer,Integer> hm =new HashMap<>();
            hm.put(0,-1);
            int ans = Integer.MAX_VALUE;
            for(int i=0;i<n;i++){
                curr=(curr%p+nums[i]%p)%p;
                int tofind = ((curr%p-x%p)+p)%p;
                if(hm.containsKey(tofind)){
                    ans = Math.min(ans,i-hm.get(tofind));
                }
               hm.put(curr,i);
            }

        if( ans == Integer.MAX_VALUE || ans==n ) return -1;

        return ans;


    }
}