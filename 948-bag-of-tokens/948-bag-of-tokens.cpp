class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int endIndx=(int)tokens.size()-1,currIndx=0;
        int maxScore=0,score=0;
        for(int i=0;i<=endIndx;i++)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                score++;
            }
            else if(score>0)
            {
                if(tokens[i]<=power+tokens[endIndx])
                {
                    power+=tokens[endIndx--];
                    power-=tokens[i];
                }
                else 
                    break;
            }
            maxScore=max(maxScore,score);
        }
        return maxScore;
    }
};