class Solution {
public:
    
    long long wonderfulSubstrings(string word) {
        map<int,int>freq;
        long long ans=0;
        int pre=0;
        freq[0]=1;
        for(int i=0;i<word.size();i++)
        {
            pre=(pre^(1<<(word[i]-'a')));
            int curr=pre;
            ans+=freq[curr];
            for(int i=0;i<10;i++)
            {
                curr=pre^(1<<i);
                ans+=freq[curr];
            }
            freq[pre]++;
        }
        return ans;
    }
};