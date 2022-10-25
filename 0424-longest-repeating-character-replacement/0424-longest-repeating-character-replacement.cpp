class Solution {
public:
int characterReplacement(string s, int k)
{
    int n = s.size(), i = 0, st = 0, tbr = 0, res = 1, mf = 0, mfc;
    // st is start of window
    // tbr is number of characters to be replaced
    // mf is max freq of among the characters
    // m stores freq of characters in current window
    map<int, int> m;
    if (n == k)
        return n;
    while (i < n)
    {
        m[s[i]]++;
        mf = 0;
        mfc = 0;
        for (auto [c, f] : m)
        {
            if (mf < f)
            {
                mf = f;
                mfc = c;
            }
        }
        tbr = (i - st + 1) - mf;
        if (tbr <= k)
            res = max(res, i - st + 1);
        while (st < i and tbr > k)
        {
            tbr--;
            m[s[st]]--;
            st++;
        }
        i++;
    }
    return res;
}
};
