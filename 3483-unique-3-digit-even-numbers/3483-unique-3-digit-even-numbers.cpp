class Solution {
    int arr[3];
    int taken[20];
    int cnt = 0;
    set<int> st;
    void rec(int level,vector<int>& digits,int n){

        if(level==3){
            int number = 0;
            int pow = 1;
            for(int i=2;i>=0;i--){
                    number+= pow*arr[i];
                    pow*=10;
            }

            if(number%2==0)  st.insert(number);

            if(to_string(number).length()<3){
                st.erase(number);
            }

            return ;
        }

        for(int i=0;i<n;i++){
            if(!taken[i]){
                arr[level]=digits[i];
                taken[i]=1;
                rec(level+1,digits,n);
                arr[level]=0;
                taken[i]=0;
            }

        }

    }
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        
        rec(0,digits,n);
        return st.size();

    }
};