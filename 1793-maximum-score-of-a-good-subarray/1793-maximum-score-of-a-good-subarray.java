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

        Stack<Integer> st2 = new Stack<>();

        for(int i=n-1;i>=0;i--){

                while(!st2.isEmpty() && nums[st2.peek()]>=nums[i]){
                    st2.pop();
                }


                if(st2.isEmpty()){
                    nextmin[i]=n;
                }else{
                    nextmin[i]=st2.peek();
                }
                st2.push(i);

        }

        // System.out.println(Arrays.toString(prevmin));
        // System.out.println(Arrays.toString(nextmin));

        int ans = 0;
        for(int i=0;i<n;i++){

            if(nextmin[i]-1>=k && prevmin[i]+1<=k){
                // System.out.println(nums[i]*(nextmin[i]-prevmin[i]-1));
                ans = Math.max(ans , nums[i]*(nextmin[i]-prevmin[i]-1));
            }
        }


        return ans;

    }
}