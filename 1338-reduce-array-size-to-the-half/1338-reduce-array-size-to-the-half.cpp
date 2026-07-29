class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n =arr.size();

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        priority_queue<int> pq;
        for(auto v: mp){
            pq.push(v.second);
        }

        int ans  = 0;
        int len = n;
        int q = n/2;
        while(!pq.empty() && len>q){
            len-=pq.top();
            pq.pop();
            ans++;
        }
 

        return ans;
    }
};