class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;

        int t =n;

        while(n>0){
            int q = n%10;
            sum+=q;
            product*=q;
            n/=10;
        }

        int q = sum+product;
        return (t%q)==0;
    }
};