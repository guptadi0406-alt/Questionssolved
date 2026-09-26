class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        int n = knowledge.size();

        for(int i=0;i<n;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string ns = "";
        string news = "";

        bool isbracket = false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                isbracket = true;
            }else if(s[i]==')'){
                isbracket = false;

                auto it = mp.find(news);

                if(it!=mp.end()){
                    ns+=mp[news];
                }else{
                    ns+="?";
                }
                
                news = "";
            }else{
                if(isbracket){
                    news+=s[i];
                }else{
                    ns+=s[i];
                }
            }
        }


        return ns;
    }
};