class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;

        int i=0;int j=0;
        int ans = 0;
        int maxfreq=0;

        while(j<n){

            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            
            if(maxfreq>2){

                while(s[i]!=s[j]){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }

                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                maxfreq--;
            }

            ans = max(ans,j-i+1);
            j++;
        }



        return ans ;



    }
};