class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                sum+=nums[i];
            }else{
                break;
            }
        }
        
        while(st.find(sum)!=st.end()){
            sum++;
        }

        return sum;
    }
};