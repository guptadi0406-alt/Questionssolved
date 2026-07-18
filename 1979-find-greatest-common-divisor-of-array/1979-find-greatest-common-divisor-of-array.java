class Solution {

    int gcd(int a,int b){
        if(b==0) return a;

        return gcd(b,a%b);
    }
    public int findGCD(int[] nums) {
        
        int n=nums.length;
        int mini=0;int maxi=0;
        
        for(int i=0;i<n;i++){
            if(nums[mini]>nums[i]) mini=i;
            if(nums[maxi]<nums[i]) maxi=i;
        }

        return gcd(nums[mini],nums[maxi]);
    }
}