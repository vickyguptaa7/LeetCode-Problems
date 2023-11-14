class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>freqRight(26,0),freqLeft(26,0);
        for(auto ch:s)
        {
            freqRight[ch-'a']++;
        }
        int cntr=0;
        vector<vector<int>>taken(26,vector<int>(26,0));
        for(auto ch:s)
        {
            freqRight[ch-'a']--;
            for(int i=0;i<26;i++)
            {
                if(taken[i][ch-'a']==0&&freqLeft[i]&&freqRight[i])
                {
                    cntr++;
                    taken[i][ch-'a']=1;
                }
            }
            freqLeft[ch-'a']++;     
        }
        return cntr;
    }
};