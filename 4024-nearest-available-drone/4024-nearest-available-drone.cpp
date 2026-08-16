class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int ans = INT_MAX;
        int mini = 0;
        for(int i=0;i<n;i++){
            int q = abs(target[0] - drones[i][0])+ abs(target[1] - drones[i][1]);

            if(q<=drones[i][2]){
                if(ans > q){
                    ans = q;
                    mini = i;
                }
            }
        }

        if(ans == INT_MAX) return -1;
        return mini ;
    }
};