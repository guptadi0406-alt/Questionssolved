class Solution {
    public int maximumScore(int[] nums, int k) {
        
        int n=nums.length;

        int prevmin[]=new int[n];
        int nextmin[]=new int[n];

        Stack<Integer> st1 = new Stack<>();

        for(int i=0;i<n;i++){

                while(!st1.isEmpty() && nums[st1.peek()]>=nums[i]){
                    st1.pop();
                }


                if(st1.isEmpty()){
                    prevmin[i]=-1;
                }else{
                    prevmin[i]=st1.peek();
                }
                st1.push(i);

        }

       st1.clear();

        for(int i=n-1;i>=0;i--){

                while(!st1.isEmpty() && nums[st1.peek()]>=nums[i]){
                    st1.pop();
                }


                if(st1.isEmpty()){
                    nextmin[i]=n;
                }else{
                    nextmin[i]=st1.peek();
                }
                st1.push(i);

        }

        

        int ans = 0;
        for(int i=0;i<n;i++){

            if(nextmin[i]-1>=k && prevmin[i]+1<=k){
             
                ans = Math.max(ans , nums[i]*(nextmin[i]-prevmin[i]-1));
            }
        }


        return ans;

    }
}