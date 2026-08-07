class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int largest = 0;
        int chunk=0;
        for(int i=0;i<n;i++){
            largest=max(largest,arr[i]);

            if(i==largest){
                chunk++;
            }
        }


        return chunk;
    }
};