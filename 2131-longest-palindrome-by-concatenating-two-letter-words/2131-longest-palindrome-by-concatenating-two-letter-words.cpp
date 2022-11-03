class Solution
{
    public:

        int longestPalindrome(vector<string> &words)
        {
            map<string, int> mmp;
            for (int i = 0; i < words.size(); i++)
            {
                mmp[words[i]]++;
            }
            int cnt = 0;
            bool isOddPresent = false;
            for (auto x: mmp)
            {
                if (x.first[0] == x.first[1])
                {

                    if (x.second &1)
                    {
                        isOddPresent = true;
                        cnt += x.second - 1;
                    }
                    else
                        cnt += x.second;
                }
                else
                {
                    string rev;
                    rev += x.first[1];
                    rev += x.first[0];
                    if (mmp.count(rev))
                    {
                        cnt += (2* min(x.second, mmp[rev]));
                        mmp[rev] = 0;
                    }
                }
            }
            return (cnt + isOddPresent) *2;
        }
};