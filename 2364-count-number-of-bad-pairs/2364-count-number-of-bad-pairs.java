class Solution {
    public long countBadPairs(int[] nums) {

        long n = nums.length;
        long total = (n*(n-1))/2;


        HashMap<Integer,Integer> hm = new HashMap<>();
        long ans = 0;


        for(int i=0;i<n;i++){
            ans+=hm.getOrDefault(i-nums[i],0);
            hm.put(i-nums[i],hm.getOrDefault(i-nums[i],0)+1);

        }

        return total-ans ;

    }
}