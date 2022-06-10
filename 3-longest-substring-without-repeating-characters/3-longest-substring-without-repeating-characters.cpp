class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>oset;
        int prev=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(!oset.count(s[i]))
            {
                oset.insert(s[i]);
            }
            else
            {
                oset.erase(s[prev++]);
                i--;
            }
            ans=max(ans,(int)oset.size());
        }
        return ans;
    }
};