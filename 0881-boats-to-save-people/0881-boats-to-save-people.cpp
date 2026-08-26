class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n = arr.size();

        sort(arr.begin(),arr.end());

        int i=0;int j=n-1;
        int ans = 0;

        int sum =0;
        vector<int> mark(n,0);
        while(i<j){

            if(arr[i]+arr[j]>limit){
                mark[j]=1;
                ans++;
                j--;
        
            }else{
                ans++;
                mark[i]=1;
                mark[j]=1;
                i++;
                j--;
            }
        }

        for(int i=0;i<n;i++) {
            if(mark[i]==0) ans ++;
        }

        return ans ;
    }
};