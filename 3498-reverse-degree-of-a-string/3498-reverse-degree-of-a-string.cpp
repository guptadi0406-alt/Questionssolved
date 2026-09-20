class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        int n = s.length();
        map<char,int> mp;

        for(int i=1;i<=26;i++){
            mp['a'+26-i] = i;
        }

        for(int i=0;i<n;i++){
            ans += (i+1)*(mp[s[i]]);
        }

        return ans ;
    }
};