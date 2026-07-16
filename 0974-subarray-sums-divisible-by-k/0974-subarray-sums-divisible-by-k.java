class Solution {
    public int subarraysDivByK(int[] nums, int k) {

        int n = nums.length;
        int curr = 0;

        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,1);

        int ans = 0;
        for(int i=0;i<n;i++){
            curr=((curr%k+nums[i]%k)+k)%k;
            ans +=hm.getOrDefault(curr%k,0);
            hm.put(curr%k,hm.getOrDefault(curr%k,0)+1);
            
        }


        return ans;
    }
}