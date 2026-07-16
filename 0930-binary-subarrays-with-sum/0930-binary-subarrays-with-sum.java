class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        
        int n = nums.length;

        int curr = 0;
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,1);
        int ans = 0;
        for(int i=0;i<n;i++){
            
            curr+=nums[i];
            ans+=hm.getOrDefault(curr-goal,0);
            hm.put(curr,hm.getOrDefault(curr,0)+1);

        }

        return ans;
    }
}