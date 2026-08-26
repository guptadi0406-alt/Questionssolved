class Solution {

    int atmost(vector<int>& arr, int k){

        map<int,int> mp;

        int n = arr.size();
        int head = -1;int tail=0;
        int ans = 0;
        while(tail<n){

            while(head+1<n && ( mp.size()<k || mp.count(arr[head+1]) > 0 )){
                head++;
                mp[arr[head]]++;
            }

            int len = head-tail+1;
            ans+=len;

            if(tail<=head){
                mp[arr[tail]]--;

                if(mp[arr[tail]]==0){
                    mp.erase(arr[tail]);
                }

                tail++;
            }else{
                tail++;
                head=tail-1;
            }
        }

        return ans ;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }


};