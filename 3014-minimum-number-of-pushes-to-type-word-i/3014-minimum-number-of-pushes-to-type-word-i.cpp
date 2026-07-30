class Solution {
public:
    int minimumPushes(string word) {
        int freq[26]={0};
        for(auto ch:word)
            freq[ch-'a']++;
        int cnt=1,val=1,ans=0;
        for(int i=0;i<26;i++)
        {
            cnt+=(freq[i]!=0);
            ans+=freq[i]!=0?val:0;
            if((cnt%9)==0)
            {
                val++;
                cnt=1;
            }
        }
        return ans;
    }
};