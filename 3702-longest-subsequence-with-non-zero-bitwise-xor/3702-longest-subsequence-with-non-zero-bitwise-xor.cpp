class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int a = 0;
        for(int j=0;j<n;j++){
            a=a^nums[j];
        }

        cout << a << " ";
        if(a!=0) return n;

        int k = 0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                a=a^nums[j];
                cout << a << " ";
                k++;
                if(a!=0) return n-k;
            }else{
                
            }
        }

        return 0;
    }
};