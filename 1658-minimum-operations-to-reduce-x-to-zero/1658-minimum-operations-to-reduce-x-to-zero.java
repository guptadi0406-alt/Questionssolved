class Solution {
    public int minOperations(int[] arr, int x) {
        
            long n = arr.length;

            long sum =0;
            for(int i=0;i<n;i++) sum+=arr[i];

            long target = sum-x;

            if(target==0){
                return (int)n;
            }


            HashMap<Long,Integer> hm = new HashMap<>();
            hm.put(0l,-1);
              
            long curr=0;
            long max = Integer.MIN_VALUE;
            for(int i=0;i<n;i++){

                    curr+=arr[i];
                    long tofind = curr - target;
                 
                    if(hm.containsKey(tofind)){
                        max=Math.max(max,i-hm.get(tofind));
                    }

                    hm.put(curr,i);
            }

        if(max == Integer.MIN_VALUE){
                return -1;
         }
        return (int)(n-max);
    }
}