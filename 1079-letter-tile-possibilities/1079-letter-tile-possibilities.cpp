class Solution {
    int ans = 0;
    vector<string> allset;
    map<char,int> freq;
    vector<pair<char,int>> valfreq;

    void rec(int level,string s){
        if(level==valfreq.size()){

            if(s.length()>0){
                allset.push_back(s);
            }
            return ;
        }

        for(int i=0;i<=valfreq[level].second;i++){
            string k = "";

            for(int j=0;j<i;j++){
                k+=valfreq[level].first;
            }
            rec(level+1,s+k);
        }
    } 


    void per (int level,string s , vector<pair<char,int>>& valuefreq,int n){
        if(level==n){
            ans++;
            return ;
        }

        for(int i=0;i<valuefreq.size();i++){

            if(valuefreq[i].second>0){
                valuefreq[i].second--;
                per(level+1,s+valuefreq[i].first,valuefreq,n);
                valuefreq[i].second++;

            }
        }
    }  

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length();

        for(int i=0;i<n;i++){
            freq[tiles[i]]++;
        }
        for (auto v : freq){
            valfreq.push_back(v);
        }

        rec(0,"");

        for(auto k:allset){
            if(k.length()>1){

                map<char,int> freq1;
                vector<pair<char,int>> valfreq1;

                for(int i=0;i<k.length();i++){
                    freq1[k[i]]++;
                }

                for (auto v : freq1){
                    valfreq1.push_back(v);
                }

                per(0,"",valfreq1,k.length());
            }else{
                ans++;
            }
        }


        return ans;

    }
};