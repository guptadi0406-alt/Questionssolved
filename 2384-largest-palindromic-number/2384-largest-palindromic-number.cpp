class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int> mp;
        int n = num.length();
        for(int i=0;i<n;i++){
            mp[num[i]]++;
        }

        string largest = "";
        string ans = "";
        for(auto it = mp.rbegin();it!=mp.rend();++it){

           
                    int q = (it->second)/2;
                    if(it->second%2!=0){
                        if(largest.length()==0) largest = it->first;
                    }

                    for(int i=0;i<q;i++){
                        ans+=it->first;
                    }
        }

        string ns = ans;
        reverse(ns.begin(),ns.end());
        ans+=largest;
        ans+=ns;

        int i=0;int j=ans.length()-1;

        while(ans[i]=='0' && ans[j]=='0' && i<=j){
            i++;
            j--;
        }
        string ans2="";
        for(int k =i;k<=j;k++){
            ans2+=ans[k];
        }

        if(ans2 == "") return "0";


        return ans2;

    }
};