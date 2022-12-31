class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>freq;
        for(auto x:s)
            freq[x]++;
        int common=0;
        for(auto x:t)
        {
            if(freq.count(x))
            {
                freq[x]--;
                common++;
                if(freq[x]==0)
                    freq.erase(x);
            }
        }
        int ans=s.size()+t.size();
        ans-=2*common;
        return ans;
    }
};