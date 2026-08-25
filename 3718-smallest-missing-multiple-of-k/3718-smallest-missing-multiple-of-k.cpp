class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }


        int t = k;

        while(true){
            auto it = st.find(t);
            cout << t << " ";
            if(it==st.end()){
                return t;
            }

            t=t+k;
        }

        return -1;
    }
};