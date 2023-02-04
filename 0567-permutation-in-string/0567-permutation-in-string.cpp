class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>freq1,freq2;
        for(auto x:s1)
            freq1[x]++;
        int prev=0;
        for(int i=0;i<s2.size();i++)
        {
            freq2[s2[i]]++;
            if(i-prev+1>s1.size())
            {
                freq2[s2[prev++]]--;
                if(freq2[s2[prev-1]]==0)
                    freq2.erase(s2[prev-1]);
            }
            if(freq1==freq2)
                return true;
        }
        return false;
    }
};