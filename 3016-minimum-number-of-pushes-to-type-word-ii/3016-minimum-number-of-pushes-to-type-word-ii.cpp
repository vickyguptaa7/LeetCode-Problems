class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++)
        {
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int cnt=0, val=1,ans=0;
        for(int i=0;i<26;i++)
        {
            if(!freq[i])
                break;
            cnt++;
            ans+=val*freq[i];
            if(cnt%8==0)
                val++;
        }
        return ans;
    }
};