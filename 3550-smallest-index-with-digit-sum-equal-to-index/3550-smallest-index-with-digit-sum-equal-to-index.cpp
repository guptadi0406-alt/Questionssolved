class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            int sum=0;
            
            int t =nums[i];
            while(t>0){
                sum+=t%10;
                t/=10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};