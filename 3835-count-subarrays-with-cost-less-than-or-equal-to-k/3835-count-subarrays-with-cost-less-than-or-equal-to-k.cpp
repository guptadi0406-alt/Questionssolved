class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();

        multiset<int> mt;

        int head=-1;int tail=0;long long  ans = 0;

        while(tail<n){
            
            if (head < tail) {
                head++;
                mt.insert(nums[head]);
            }

            while(head+1<n && !mt.empty() && 1LL * (max(*mt.rbegin(), nums[head+1])- min(*mt.begin(), nums[head+1]))* (head-tail+2) <= k){
                head++;
                mt.insert(nums[head]);
            }

            int len = (head-tail+1);
            ans +=len;


            if(tail<=head){
                mt.erase(mt.find(nums[tail]));
                tail++;
            }else{
                tail++;
                head=tail-1;
            }

        }

        return ans ;

    }
};