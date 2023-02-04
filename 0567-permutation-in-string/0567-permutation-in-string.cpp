class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>freq;
        for(auto x:s1)
            freq[x]++;
        int prev=0;
        for(int i=0;i<s2.size();i++)
        {
            freq[s2[i]]--;
            
            if(freq[s2[i]]==0)
                freq.erase(s2[i]);
            
            if(i-prev+1>s1.size())
            {
                freq[s2[prev++]]++;
                if(freq[s2[prev-1]]==0)
                    freq.erase(s2[prev-1]);
            }
            
            if(freq.empty())
                return true;
        }
        return false;
    }
};