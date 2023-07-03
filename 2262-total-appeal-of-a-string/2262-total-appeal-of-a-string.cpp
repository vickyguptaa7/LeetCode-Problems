class Solution
{
    public:
        long long appealSum(string s)
        {
            vector<vector < int>> indxrr(26);
            for (int i = 0; i < s.size(); i++)
            {
                indxrr[s[i] - 'a'].push_back(i);
            }
            int n = s.size();
            long long appeal = 0;
            for (int i = 0; i < 26; i++)
            {
                if(indxrr[i].empty())
                    continue;
                int prev = -1, len = 0;
                long long count=0;
                for (int j = 0; j < indxrr[i].size(); j++)
                {
                    int len = (indxrr[i][j] - prev-1);
                    prev = indxrr[i][j];
                    if (len > 0)
                    {
                        count +=  (len *1ll *(len + 1)) / 2;

                    }
                }
                len = n - prev - 1;
                count += (len *1ll *(len + 1)) / 2;       
                appeal+=(n *1ll *(n + 1 ) / 2) -count;
            }
            return appeal;
        }
};