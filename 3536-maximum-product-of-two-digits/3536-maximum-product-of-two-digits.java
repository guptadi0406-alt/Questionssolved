class Solution {
    public int maxProduct(int n) {
        String s=String.valueOf(n);
        int max1=Integer.MIN_VALUE;
        int maxi1=0;
        int max2=Integer.MIN_VALUE;
       
        int nums[]=new int[s.length()];
        for(int i=0;i<s.length();i++){
             nums[i]=Character.getNumericValue(s.charAt(i));
        }


        for(int i=0;i<nums.length;i++){
            if(max1<nums[i]){
                max1=nums[i];
                maxi1=i;
            }
        }
        nums[maxi1]=0;

        for(int i=0;i<nums.length;i++){
            if(max2<nums[i]){
                max2=nums[i];
              
            }
        }
        System.out.println(max1);
        System.out.println(max2);

            return max1*max2;
        
    }
}