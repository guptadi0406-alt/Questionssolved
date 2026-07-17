class Solution {
    public int minOperations(int[] arr, int x) {
        
            int n = arr.length;

            int sum =0;
            for(int i=0;i<n;i++) sum+=arr[i];

            int target = sum-x;

            if(target==0) return n;


            HashMap<Integer,Integer> hm = new HashMap<>();
            hm.put(0,-1);
            int curr=0;
            int max = Integer.MIN_VALUE;
            for(int i=0;i<n;i++){

                    curr+=arr[i];
                    int tofind = curr - target;
                    if(hm.containsKey(tofind)){
                        max=Math.max(max,i-hm.get(tofind));
                    }

                    hm.put(curr,i);
            }

        if(max == Integer.MIN_VALUE){
                return -1;
         }
        return n-max;
    }
}