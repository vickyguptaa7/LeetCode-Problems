class Solution {
public:
    string getHint(string secret, string guess) {
        int bullsCnt=0;
        vector<int>secretDigFreq(10,0),guessDigFreq(10,0);
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                bullsCnt++;
            secretDigFreq[secret[i]-'0']++;
            guessDigFreq[guess[i]-'0']++;
        }
        int cowsCnt=0;
        for(int i=0;i<10;i++)
        {
            cowsCnt+=min(secretDigFreq[i],guessDigFreq[i]);
        }
        cowsCnt-=bullsCnt;
        return to_string(bullsCnt)+"A"+to_string(cowsCnt)+"B";
    }
};