class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int n = nums.length;
        int curr = 0;
        int ans =0;
        for(int i=0;i<n;i++){
           curr+=nums[i];

           if(curr==0) ans++;
        }
        return ans ;
    }
}