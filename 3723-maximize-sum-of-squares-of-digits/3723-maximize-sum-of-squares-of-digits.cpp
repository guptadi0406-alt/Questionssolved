class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        int t =sum;

        for(int i=0;i<num;i++){

            if(sum>9){
                sum-=9;
                s+="9";
            }else{
                s+=to_string(sum);
                sum=0;
            }

        }


        int sumgenerate = 0;
        for(int i=0;i<s.length();i++){
            sumgenerate+=(s[i]-'0');
        }
     

        if(sumgenerate!=t) {
            return "";
        }


        return s;
    }
};