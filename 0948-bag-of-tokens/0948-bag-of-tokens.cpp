class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0,n=tokens.size();
        int tail=0,head=n-1;
        int score=0;
        sort(tokens.begin(),tokens.end());
        while(tail<=head)
        {
            if(tokens[tail]<=power)
            {
                score++;
                power-=tokens[tail];
                tail++;
            }
            else if(score)
            {
                power+=tokens[head];
                score--;
                head--;
            }
            else
            {
                break;
            }
            ans=max(ans,score);
        }
        return ans;
    }
};