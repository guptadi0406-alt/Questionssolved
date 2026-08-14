class Solution {

    int check(int mid,vector<int>& dist, double hour){
        int n = dist.size();
        double a = 0;

        for(int i=0;i<n-1;i++){
            a += ceil((double)(dist[i])/(double)(mid));
        }
        a += (dist[n-1]/(double)(mid));
       

        return a<=hour;

    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n = dist.size();
      
        double i=1; int j = 1e7;
        int ans = -1;

        while(i<=j){

            int mid = i+(j-i)/2;
            if(check(mid,dist,hour)) {
                ans = mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }

        return ans ;
    }
};