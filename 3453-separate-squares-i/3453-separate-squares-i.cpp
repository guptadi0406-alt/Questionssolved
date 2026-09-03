class Solution {

    int check(long double mid , vector<vector<int>>& squares){
        long double areadown  = 0;
        long long totalarea  = 0;

        int n = squares.size();
       

        for(int i=0;i<n;i++){
            int x = squares[i][1];
            int y = squares[i][1];
            int l = squares[i][2];

            totalarea += 1LL*(l)*(l);

            if(y+l>mid && y<mid ){
                areadown += 1LL*(mid-y)*(l);
            }else if(y+l<=mid){
                areadown += 1LL*(l)*(l);
            }

          

        }
        
        long double areaup  = totalarea - areadown;
      


        return areaup<=areadown;
    }   
public:
    double separateSquares(vector<vector<int>>& squares) {

            int n = squares.size();
            int maxy = squares[0][1]+squares[0][2];
            for(int i=1;i<n;i++){
                maxy=max(maxy,squares[i][1]+squares[i][2]);
            }
            long double ans =0;
            long double low =0;
            long double high = maxy;
          

            for(int i=0;i<=80;i++){
                long double mid = (low+high)/2;

             
                if(check(mid,squares)){
                    ans =  mid;
                    high=mid;
                }else{
                    low = mid;
                }
            }

        return ans;
    }   
};