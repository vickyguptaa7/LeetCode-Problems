class Solution {
public:
    int helper(int iter,string &num,vector<string>&digits,bool isStart,
               bool ristrict,vector<vector<vector<int>>>&dp)
    {
        if(iter==num.size())
        {
            return isStart;
        }
        if(dp[iter][isStart][ristrict]!=-1)
            return dp[iter][isStart][ristrict];
        int end=(ristrict)?num[iter]-'0':10;
        int noOfNums=0;
        if(!isStart)
        {
            noOfNums+=helper(iter+1,num,digits,false,false,dp);
        }
        bool isEnd=false;
        for(int i=0;i<digits.size();i++)
        {
            if(end<=digits[i][0]-'0')
            {
                isEnd=(end==digits[i][0]-'0');
                break;
            }
            else
            {
                noOfNums+=helper(iter+1,num,digits,true,false,dp);
            }
        }
        if(isEnd&&ristrict)
        {
            noOfNums+=helper(iter+1,num,digits,true,true,dp);
        }
        return dp[iter][isStart][ristrict]=noOfNums;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num=to_string(n);
        vector<vector<vector<int>>>dp(num.size(),vector<vector<int>>(2,
                                                    vector<int>(2,-1)));
        return helper(0,num,digits,false,true,dp);
    }
};