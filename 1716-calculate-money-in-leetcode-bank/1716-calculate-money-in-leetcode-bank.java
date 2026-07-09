class Solution {
    public int totalMoney(int n) {
        
        int q = n/7;

        int rem = n%7;

    

        int sum=0;

        for(int i=0;i<q;i++){

            sum+=((7+i+1)*(7+i))/2;
            sum-=((i+1)*(i))/2;

        }

        sum+=((rem+q+1)*(rem+q))/2;
        sum-=(q)*(q+1)/2;



        return sum;
    }
}