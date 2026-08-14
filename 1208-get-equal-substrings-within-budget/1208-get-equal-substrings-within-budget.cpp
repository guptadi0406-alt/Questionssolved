class Solution {


    bool check(int mid,string s, string t, int maxCost){

        int n = s.length();
        int a = 0;

        for(int i=0;i<mid;i++){
            if(s[i]!=t[i]) a+= abs(s[i]-t[i]);
        }

        if(a<=maxCost) return 1;
        int i=0;int j = mid;
        while(j<n){
            if(s[i]!=t[i]) a-= abs(s[i]-t[i]);
            if(s[j]!=t[j]) a+= abs(s[j]-t[j]);

            if(a<=maxCost) return 1;
        

            i++;j++;
        }


        return 0;
    }

public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length();

        int i=0;int j=n;int ans =0;

        while(i<=j){
            int mid = i+(j-i)/2;
            if(check(mid,s,t,maxCost)){
                ans = mid ;
                i=mid+1;
            }else{
                j= mid-1;
            }
        }
        return ans;
    }
};