class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
            int m = bookings.length;
            int ans[]=new int[n];
            for(int i=0;i<m;i++){
                int f = bookings[i][0]-1;
                int l = bookings[i][1]-1;
                int v = bookings[i][2];

                ans[f]+=v;
                if(l+1<n) ans[l+1]-=v;
            }

            for(int i=1;i<n;i++){
                    ans[i]+=ans[i-1];
            }

            return ans;
    }
}