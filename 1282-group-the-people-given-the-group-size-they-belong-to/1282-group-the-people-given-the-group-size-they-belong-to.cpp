class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {


        vector<vector<int>> ans;
        multimap<int,int> mp;
        int n = groupSizes.size();

        for( int i=0;i<n;i++){
            mp.insert(make_pair(groupSizes[i],i));
        }

        int d=0;
        vector<int> l;
        for(auto v :mp){
            d=v.first;
            l.push_back(v.second);

            if(l.size()==d){
                ans.push_back(l);
                l.clear();
            }
         
        } 

        return ans ;
        
    }
};