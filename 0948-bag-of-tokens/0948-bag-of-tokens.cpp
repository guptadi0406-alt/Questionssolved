class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(),tokens.end());

        int score=0;

        int i = 0;
        int j= n-1;

        while(i<=j){

            cout << i << " " << score << " " << power << '\n';
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }else{
                if(j-i>=1){
                    if(score>0){
                        power+=tokens[j];
                        score-=1;
                    }
                    j--;
                }else break;
            }
        }

        return score;
    }
};