class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum=0;
        int tail=0;int head=-1;long long  ans =0;
        
        while(tail<n){

            while(head+1<n && (long long)( (long long)(sum+nums[head+1]) * (long long)(head-tail+2) < k ) ){
                head++;
                sum+=nums[head];
            }
          
            int len = head-tail+1;
            ans += len;

            if(tail<=head){
                sum-=nums[tail];
                tail++;
            }else{
                tail++;
                head=tail-1;
            }
        }

        return ans ;
    }
};