class Solution {
public:
int characterReplacement(string s, int k)
{
    map<char, int> windowFreq;
    map<int, int> fFreq;
    int resWindowSize = 1;
    int curr = 0, prev = 0, n = s.size();
    while (curr < n)
    {
        int mostFrequentCount = 0;
        if (!fFreq.empty())
        {
            mostFrequentCount = fFreq.rbegin()->first;
        }
        if (curr - prev - mostFrequentCount <= k)
        {
            int oldFreq = 0;
            if (fFreq.count(windowFreq[s[curr]]))
            {
                oldFreq = windowFreq[s[curr]];
                fFreq[windowFreq[s[curr]]]--;
                if (fFreq[windowFreq[s[curr]]] == 0)
                {
                    fFreq.erase(windowFreq[s[curr]]);
                }
            }
            fFreq[oldFreq + 1]++;
            windowFreq[s[curr]]++;
            curr++;
            mostFrequentCount = fFreq.rbegin()->first;
            if (curr - prev - mostFrequentCount <= k)
                resWindowSize = max(resWindowSize, curr - prev);
        }
        else
        {
            while (curr > prev && curr - prev - mostFrequentCount > k)
            {
                windowFreq[s[prev]]--;
                int oldFreq = windowFreq[s[curr]];
                fFreq[windowFreq[s[curr]]]--;
                if (fFreq[windowFreq[s[curr]]] == 0)
                {
                    fFreq.erase(fFreq[windowFreq[s[curr]]]);
                }
                if (oldFreq != 1)
                    fFreq[oldFreq - 1]++;
                if (windowFreq[s[prev]] == 0)
                {
                    windowFreq.erase(s[prev]);
                }
                if (windowFreq.empty())
                {
                    mostFrequentCount = 0;
                }
                else
                {
                    mostFrequentCount = fFreq.rbegin()->first;
                }
                prev++;
            }
        }
    }
    return resWindowSize;
}

};