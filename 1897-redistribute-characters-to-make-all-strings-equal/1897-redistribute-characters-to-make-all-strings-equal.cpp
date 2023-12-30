class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26);
        for(auto word:words)
        {
            for(auto ch:word)
            {
                freq[ch-'a']++;
            }
        }
        int size=words.size();
        for(int i=0;i<26;i++)
        {
            if(freq[i]%size!=0)
                return false;
        }
        return true;
    }
};