class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minn = *min_element(nums.begin(),nums.end());
        int x = 0;
        for(int i=0;i<n;i++){
            x += (nums[i]-minn);
        }

        return x;
    }
};