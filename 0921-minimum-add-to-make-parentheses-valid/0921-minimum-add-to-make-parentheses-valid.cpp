class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int n = s.length();
        int open = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else {
                open --;
            }
            if(open < 0) ans +=1;
            if(s[i]==')' && open < 0) open = 0;
        }
        // cout << open << '\n';
        if(open > 0) ans +=open ;
        return ans ;
    }
};