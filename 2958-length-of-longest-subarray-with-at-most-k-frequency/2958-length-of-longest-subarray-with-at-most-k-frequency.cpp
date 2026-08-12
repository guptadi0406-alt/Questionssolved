class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;

        int i=0;int j=0;
        int ans = 0;
        int maxfreq=0;

        while(j<n){

            mp[nums[j]]++;
            maxfreq=max(maxfreq,mp[nums[j]]);
            
            if(maxfreq>k){

                while(nums[i]!=nums[j]){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }

                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                maxfreq--;
            }

            // for(auto v : mp){
            //     cout << v.first << " -  " << v.second << '\n';
            // }
            // cout << '\n';

            ans = max(ans,j-i+1);
            j++;
        }



        return ans ;

    }
};