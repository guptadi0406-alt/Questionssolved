class Solution {

    static int check(int mid , vector<int>& arr, int m){
            int n = arr.size();

            int a =1;
            int j=0;
            for(int i=1;i<n;i++){
                if(arr[i] - arr[j] >= mid){
                    a++;
                    j=i;
                }
            }

            return a>=m;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();

        sort(position.begin(),position.end());

        int i =0;int j = position[n-1]-position[0];
        int ans = 0;

        while(i<=j){
            int mid = i+(j-i)/2;

            if(check(mid,position,m)){
                ans = mid;
                i = mid+1;
            }else{
                j= mid-1;
            }
        }

        return ans;

    }
};