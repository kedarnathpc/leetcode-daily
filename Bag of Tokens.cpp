class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0, j = n-1, score = 0;

        sort(tokens.begin(), tokens.end());

        while(i <= j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i];
                i++;
            }
            else {
                if(score and (i < j)){
                    score--;
                    power += tokens[j];
                    j--;
                }
                else {
                    break;
                }
            }
        }

        return score;
    }
};
