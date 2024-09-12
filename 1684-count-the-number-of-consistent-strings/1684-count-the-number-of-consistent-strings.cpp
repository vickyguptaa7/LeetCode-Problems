class Solution {
public:
    
    int charPresent(string& str)
    {
        int present=0;
        for(char ch:str)
        {
            present|=(1<<(ch-'a'));
        }
        return present;
    }
    
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedBit=charPresent(allowed);
        int res=0;
        for(auto &word:words)
        {
            if(allowedBit==(allowedBit|charPresent(word)))
            {
                res++;
            }
        }
        return res;
    }
};