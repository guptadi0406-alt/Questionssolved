class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();


        map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

 
        int ans =0;
        for(int i=0;i<n;i++){
            auto it = mp.upper_bound(nums[i]);
            if(it!=mp.end()){
                mp[it->first]--;

                if(mp[it->first]==0){
                    mp.erase(it);
                }

                ans++;
            }
        }
        return ans ;

    }
};