class Solution {

    int check(int mid,vector<int>& chargeTimes, vector<int>& runningCosts, long long budget){
        int n = runningCosts.size();

        long long sum=0;
        multiset<int> mt;

        int i=0;
        while(i<mid){
            sum+=runningCosts[i];
            mt.insert(chargeTimes[i]);
            i++;
        }
      

        
            long long q = 1LL*((*mt.rbegin()) + (1LL* mid * (sum)));
            if(q<=budget)return 1;
      

        int j=0;
        while(i<n){
            sum+=runningCosts[i];
            sum-=runningCosts[j];

            mt.insert(chargeTimes[i]);
            mt.erase(mt.find(chargeTimes[j]));
           
            long long q = 1LL*((*mt.rbegin()) + (1LL* mid * (sum)));
            if(q<=budget)return 1;
    

            i++;j++;
        }
        return 0;

    }
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {

         int n = runningCosts.size();
        int i=1;int j=n;int ans = 0;

        while(i<=j){
            int mid = i+(j-i)/2; 
            if(check(mid,chargeTimes,runningCosts,budget)){
                ans = mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }


    return ans;
    }

};