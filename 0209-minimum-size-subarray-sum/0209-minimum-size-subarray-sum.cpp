class Solution {

    bool check( vector<int>& nums,int mid,int target){
            int n = nums.size();

            int sum=0;
            for(int i=0;i<mid;i++){
                sum+=nums[i];
            }
            if(sum>=target) return 1;
            int i=0;int j=mid;

            while(j<n){

                sum+= (nums[j]-nums[i]);
                if(sum>=target) return 1;
                i++;j++;
            }
            return 0;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i=0;int j=n;int ans =0;
        while(i<=j){
            int mid = i+(j-i)/2;

            if(check(nums,mid,target)){
                ans = mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }

        return ans;
    }
};