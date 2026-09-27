class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]==')'){

                    string ns = "";
                    while(!st.empty() && st.top()!='('){
                        ns+=st.top();
                        st.pop();
                    }
                    if(!st.empty()) st.pop();

                    for(int j=0;j<ns.length();j++){
                            st.push(ns[j]);
                    }
            }else{
                st.push(s[i]);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};