class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        int t =sum;

        for(int i=0;i<num;i++){

            for(int j=9;j>=0;j--){
                if(sum-j>=0){
                    sum-=j;
                    s+=to_string(j);
                    break;
                }
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