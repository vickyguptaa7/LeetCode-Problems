class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq(26,0);
        for(auto ch:chars)
            freq[ch-'a']++;
        int res=0;
        for(auto word:words)
        {
            vector<int>f(26,0);
            for(auto ch:word)
                f[ch-'a']++;
            bool isFound=true;
            for(int i=0;i<26;i++)
            {
                if(freq[i]<f[i])
                {
                    isFound=false;
                    break;
                }
            }
            res+=isFound?word.size():0;
        }
        return res;
    }
};