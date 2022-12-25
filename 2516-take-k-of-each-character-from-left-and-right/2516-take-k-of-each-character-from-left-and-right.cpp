class Solution
{
    public:
        bool isValid(string &s, int k, map<char, int> freq, int mid)
        {
            for (int i = 0; i < mid; i++)
            {
                freq[s[i]]--;
            }
            bool isTrue = true;
            for (auto x: freq)
            {
                if (x.second < k)
                {
                    isTrue = false;
                }
            }
            if (isTrue)
                return true;
            for (int i = mid; i < s.size(); i++)
            {
                freq[s[i]]--;
                freq[s[i - mid]]++;
                isTrue = true;
                for (auto x: freq)
                {
                    if (x.second < k)
                    {
                        isTrue = false;
                    }
                }
                if (isTrue)
                    return true;
            }
            return false;
        }
    int takeCharacters(string s, int k)
    {
        map<char, int> freq;
        freq['a']=0;
        freq['b']=0;
        freq['c']=0;
        
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
        }
        for (auto x: freq)
        {
            if (x.second < k)
            {
                return -1;
            }
        }
        int low = 0, high = s.size();
        int ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isValid(s, k, freq, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return (int) s.size() - ans;
    }
};