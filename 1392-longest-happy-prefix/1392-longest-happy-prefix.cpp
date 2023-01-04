class Solution {
public:
    string longestPrefix(string s) {
        int size=s.size();
        // longest prefix logic
        vector<int>lps(size,0);
        int curr=0,next=1;
        while(next<size)
        {
            if(s[curr]==s[next])
            {
                lps[next]=curr+1;
                curr++;
                next++;
            }
            else
            {
                if(curr>0)
                {
                    curr=lps[curr-1];
                }
                else
                {
                    next++;
                }
            }
        }
        string res;
        for(int i=0;i<lps.back();i++)
        {
            res+=s[i];
        }
        return res;
    }
};