class Solution {
public:
    
    void helper(int strt,string ans,int partition,
                string &s,vector<string>&validIp)
    {
        if(strt==s.size())
        {
            if(partition==0)
            validIp.push_back(ans);
            return;
        }
        string curr;
        string ch;
        if(!ans.empty())ch=".";
        if(s[strt]=='0')
        {
            helper(strt+1,ans+ch+"0",partition-1,s,validIp);
            return;
        }
        for(int i=strt;i<s.size();i++)
        {
            curr+=s[i];
            if(stoi(curr)<256&&partition>0)
            {
                helper(i+1,ans+ch+curr,partition-1,s,validIp);
            }
            else 
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>validIp;
        helper(0,"",4,s,validIp);
        return validIp;
    }
};