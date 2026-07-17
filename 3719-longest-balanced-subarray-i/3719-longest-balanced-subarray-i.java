class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;

        int ans = 0;
            HashSet<Integer> e = new  HashSet<>();
            HashSet<Integer> o = new  HashSet<>();
        for(int i=0;i<n;i++){

            for(int j=i;j<n;j++){
                if(nums[j]%2==0) e.add(nums[j]);
                else o.add(nums[j]);
                if(e.size()==o.size()) {
                    ans = Math.max(ans,j-i+1);
                }
            }
            e.clear();
            o.clear();
        }
        return ans;
    }
}