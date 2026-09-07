class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        map<char,int> mp2;

        for(int i=0;i<m;i++){
            mp2[t[i]]++;
        }

        map<char,int> mp;

        int dist= 0;
        int head=-1;int tail=0;
        int ans = 1e9;
        pair<int,int> p = {1e5,-1e5};
        int head2=0;
        while(tail<n){
 
            while(head+1<n){
                
                bool f = true;

                for(auto v:mp2){
                    if(mp.find(v.first) == mp.end() ){
                        f=false;
                    }else{
                         if (mp[v.first]<v.second)  f=false;
                    }
                }

                if(f) {
                    break;
                }
                head++;
                mp[s[head]]++;
            }

            bool f = true;
            for(auto v:mp2){
                if(mp.find(v.first)==mp.end()){
                        f=false;
                }else{
                    if (mp[v.first]<v.second)  f=false;
                }
            }

            if(f) {

                if(head-tail+1<(p.first-p.second+1)){
                    p.first= head;
                    p.second = tail;
                }

            }
       
             

            if(tail<=head){
                mp[s[tail]]--;
                if(mp[s[tail]]==0) mp.erase(s[tail]);
                tail++;

            }else{
                tail++;
                head=tail-1;
            }
        }
        if(p.first == 1e5 ) return "";

        return s.substr(p.second,p.first-p.second+1);
    }
};