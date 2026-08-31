class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        if(k==0) return nums;



        int n = nums.size();

        vector<int> arr(n,-1);

        if(2*k+1>n) return arr;

        int i=0;
        long long sum=0;
        while(i<=(2*k) && i<n){
           
            sum+=nums[i];
            i++;
        }
       
        if(k<n){
            arr[k]=sum/((2*k)+1);
        }

        int j=0;
        while(i<n){
                sum+=(nums[i]-nums[j]);
                arr[j+k+1]=sum/((2*k)+1);
                i++;
                j++;
        }


        return arr;


    }
};