class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        for(auto ch:s)freq[ch-'a']++;
        int mn=1e9,mx=0;
        for(int i=0;i<26;i++)
        {
            if(!freq[i])continue;
            if(!(freq[i]&1))
                mn=min(mn,freq[i]);
            else 
                mx=max(mx,freq[i]);
        }
        cout<<mx<<" "<<mn;
        return mx-mn;
    }
};