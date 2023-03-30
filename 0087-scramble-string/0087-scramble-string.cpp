class Solution
{
    map<string,bool>dp;
    public:
        bool isScramble(string x, string y)
        {
            if (x.compare(y) == 0)
                return true;
            if (x.length() <= 1)
                return false;
            string change=x+"-"+y;
            if(dp.count(change))
                return dp[change];
            int n = x.length();
            bool flag = false;
            for (int k = 1; k < n; k++)
            {
                if (isScramble(x.substr(0, k), y.substr(0, k)) && isScramble(x.substr(k, n - k), y.substr(k, n - k)))
                {
                    flag = true;
                    break;
                }
                if (isScramble(x.substr(0, k), y.substr(n - k, k)) && isScramble(x.substr(k, n - k), y.substr(0, n - k)))
                {
                    flag = true;
                    break;
                }
            }
            return dp[change]=flag;
        }
};