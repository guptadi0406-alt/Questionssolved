class Solution {
    int spf[100101];
    void prcompute(){

        for(int i=1;i<=100100;i++) spf[i]=i;

        for(int i=2;i<=100100;i++){

            if(spf[i]==i){

                for(int j=2*i;j<=100100;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }

            }
        }
    }


public:
    int longestSubarray(vector<int>& nums, int k) {
            prcompute();

            int n=nums.size();

            map<int,int> mp;
            int head=-1;int tail=0;int ans =0;

            while(tail<n){

                while(head+1<n ){
                    head++;
                    int q = nums[head];

                    while(q>1){
                   
                        mp[spf[q]]++;
                        q/=spf[q];
                    }

                    if(mp.size()>k){
                        int q = nums[head];

                        while(q>1){
            
                            mp[spf[q]]--;

                            if(mp[spf[q]]==0) mp.erase(spf[q]);

                            q/=spf[q];
                        }
                        
                        head--;
                        break;
                    }
                 
                }
                ans = max(ans , head-tail+1);

                if(tail<=head){
                    int q = nums[tail];

                    while(q>1){
        
                        mp[spf[q]]--;

                        if(mp[spf[q]]==0) mp.erase(spf[q]);

                        q/=spf[q];
                    }

                    tail++;
                }else{
                    tail++;
                    head=tail-1;
                }
            }


            return ans;
    }
};