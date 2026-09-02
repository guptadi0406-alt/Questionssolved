class Solution {

    int isprime[100101];
    void precompute(){

        for(int i=2;i<=100100;i++) isprime[i]=1;

        for(int i=2;i<=100100;i++){
            if(isprime[i]==1){  
                for(int j=2*i;j<=100100;j+=i){
                    isprime[j]=0;
                }
            }
        }


    }
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n =nums.size();
        precompute();

        int cnt=0;
        multiset<int> st;

        int head1=-1;int head2=-1;int tail=0;int ans =0;

        while(tail<n){

            while(head1+1<n && (cnt<1 || !isprime[nums[head1+1]] )){
                head1++;
                if(isprime[nums[head1]]){
                    cnt++;
                }
            }


            while(head2+1<n){

                if(!isprime[nums[head2+1]]) {
                    head2++;
                    continue;
                }

                if(st.empty()){
                    head2++;
                    st.insert(nums[head2]);
                }else if(max(*st.rbegin(),nums[head2+1])-min(*st.begin(),nums[head2+1])<=k){
                    head2++;
                    st.insert(nums[head2]);
                }else{
                    break;
                }
                
            }
            

            ans += max(head2-head1,0);

            if(tail<=head1){
                if(isprime[nums[tail]]){
                    cnt--;
                }
            }else{
                head1=tail-1;
            }

            if(tail<=head2){
                if(isprime[nums[tail]]){
                    st.erase(st.find(nums[tail]));
                }
            }else{
                head2=tail-1;
            }


            tail++;
        }

        return ans;
    }
};