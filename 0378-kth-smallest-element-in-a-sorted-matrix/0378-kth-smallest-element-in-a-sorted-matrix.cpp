class Solution {
     bool check(int mid , int n , int m , int k,vector<vector<int>>& matrix){
        int a = 0;

        for(int i=0;i<n;i++){
            int ind = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            ind--;
            a+=ind+1;
        }
        return a>=k;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
            int n = matrix.size();
            int m = matrix[0].size();

            int minno = INT_MAX;
            int maxno = INT_MIN;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    minno=min(minno,matrix[i][j]);
                    maxno=max(maxno,matrix[i][j]);
                }
            }

            int i=minno;int j =maxno;
            int ans = -1;
            while(i<=j){
                int mid = i+(j-i)/2;
                if(check(mid,n,m,k,matrix)){
                    ans = mid;
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }   

            return ans;
    }
    
};

