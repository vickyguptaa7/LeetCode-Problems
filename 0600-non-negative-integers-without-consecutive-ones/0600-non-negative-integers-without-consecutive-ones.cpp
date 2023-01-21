class Solution {
public:
    
    int helper(int strt,string &binary,bool restrict,bool isPrevOne,
                vector<vector<vector<int>>>&dp)
    {
        if(strt==binary.size())
        {
            return 1;
        }
        if(dp[strt][restrict][isPrevOne]!=-1)
            return dp[strt][restrict][isPrevOne];
        
        int end=(restrict)?binary[strt]-'0':2;
        int res=0;
        for(int i=0;i<end;i++)
        {
            if(i==1&&isPrevOne)
                continue;
            res+=helper(strt+1,binary,false,i==1,dp);
        }
        if(restrict&&(!isPrevOne||end!=1))
            res+=helper(strt+1,binary,true,end==1,dp);
        
        return dp[strt][restrict][isPrevOne]=res;
    }
    string decToBinary(int n)
    {
        string s;
        while(n)
        {
            s+=(n&1)?"1":"0";
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int findIntegers(int n) {
        string binary=decToBinary(n);
        vector<vector<vector<int>>>dp(binary.size(),
                        vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(0,binary,true,false,dp);
    }
};