class Solution
{
    public:
        int minimumLengthEncoding(vector<string> &words)
        {
            string res;

            sort(words.begin(), words.end(), [](string a, string b)
            {
                return a.size() > b.size();
            });

            for (auto x: words)
            {
                if (res.find(x + "#") == string::npos)
                {
                    res += x + "#";
                }
            }
            return res.size();
        }
};