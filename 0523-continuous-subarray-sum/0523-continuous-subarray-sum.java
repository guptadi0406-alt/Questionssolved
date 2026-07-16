class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        
        int n = nums.length;
        int curr = 0;

        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,-1);


        for(int i=0;i<n;i++){
            curr=(curr%k+nums[i]%k)%k;


 
            if(hm.containsKey(curr%k)){
                    if(i-hm.get(curr%k)>=2){
                        return true;
                    }
            }else{
                hm.put(curr%k,i);
            }
        }


        return false;
    }
}