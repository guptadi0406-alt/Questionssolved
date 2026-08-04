class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> l = new ArrayList<>();
        HashSet<Integer> hs = new HashSet<>();
        int n = nums.length;

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for(int i=0;i<n;i++){
            max=Math.max(max,nums[i]);
            min=Math.min(min,nums[i]);
            hs.add(nums[i]);
        }

        for(int i=min+1;i<max;i++){
            if(!hs.contains(i)){
                l.add(i);
            }
        }

        return l;
    }
}