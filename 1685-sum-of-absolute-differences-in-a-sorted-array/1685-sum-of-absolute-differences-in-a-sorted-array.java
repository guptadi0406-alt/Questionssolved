class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;

        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int result [] = new int [n];
        
        int curr = 0;
        for(int i=0;i<n;i++){

           result[i] -= (nums[i]*(n-i-1));
           result[i] += (nums[i]*(i));
           result[i] -= (curr);
           result[i] += (sum-curr-nums[i]);


           curr+=nums[i];

        }

        return result ;
    }
}