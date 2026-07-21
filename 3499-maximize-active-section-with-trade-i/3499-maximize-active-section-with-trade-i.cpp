class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>count;
        int cnt=1;
        int ones=s[0]=='1';
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                count.push_back(cnt);
                cnt=0;
            }
            ones+=s[i]=='1';
            cnt++;
        }
        count.push_back(cnt);
        if(count.size()==1)
        {
            return s[0]=='0'?0:count[0];
        }
        int ans=ones;
        for(int i=s[0]=='1'?2:1;i<count.size()-1;i+=2)
        {
            ans=max(ans,count[i-1]+ones+count[i+1]);
        }
        // for(int i=s[0]=='0'?2:1;i<count.size()-1;i+=2)
        // {
        //     ans=max(ans,ones+count[i]-1);
        // }
        return ans;
    }
};