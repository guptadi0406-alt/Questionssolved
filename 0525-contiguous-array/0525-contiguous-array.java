class Solution {
    public int findMaxLength(int[] nums) {
        
        int n = nums.length;


        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i]=-1;
        }

        // System.out.println(Arrays.toString(nums));

        HashMap<Integer,Integer> hm = new HashMap<>();

        hm.put(0,-1);

        int curr = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            curr+=nums[i];

            if(hm.containsKey(curr)){
                ans = Math.max(ans,i-hm.get(curr));

                // System.out.println(hm.get(curr));
                // System.out.println(i);

            }else{
                hm.put(curr,i);
            }
        }


        return ans;
    }
}