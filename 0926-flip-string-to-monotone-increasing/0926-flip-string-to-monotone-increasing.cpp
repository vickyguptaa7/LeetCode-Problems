class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int preOneCnt=0,zeroCnt=0,n=s.size();
        for(auto x:s)if(x=='0')zeroCnt++;
        int minFlips=zeroCnt;
        for(auto x:s)
        {
            if(x=='0')zeroCnt--;
            else preOneCnt++;
            minFlips=min(minFlips,preOneCnt+zeroCnt);
        }
        return minFlips;
    }
};