class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freqs(26,0),freqt(26,0);
        for(auto ch:s)freqs[ch-'a']++;
        for(auto ch:t)freqt[ch-'a']++;
        int res=0;
        for(int i=0;i<26;i++)res+=abs(freqs[i]-freqt[i]);
        return res/2;
    }
};