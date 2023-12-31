class Solution {
public:
    
    int maximumLength(string s) {
        vector<int>freq[26];
        int count=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                count++;        
            }
            else
            {
                freq[s[i-1]-'a'].push_back(count);
                count=1;
            }
        }
        freq[s.back()-'a'].push_back(count);
        int res=-1;
        for(int i=0;i<26;i++)
        {
            int sz=freq[i].size();
            sort(freq[i].begin(),freq[i].end());
            if(sz>=3)
            {
                int first=freq[i][sz-3],second=freq[i][sz-2],third=freq[i][sz-1];
                res=max({res,third-2,first});
                // cout<<first<<" "<<second<<" "<<third<<"\n";
                if(second<third)
                {
                    res=max(res,second);
                }
                else
                {
                    res=max(res,second-1);
                }
            }
            else if(sz==2)
            {
                int first=freq[i][sz-2],second=freq[i][sz-1];
                res=max({res,second-2});
                if(first<second)
                {
                    res=max(res,first);
                }
                else
                {
                    res=max(res,second-1);
                }
            }
            else if(sz==1&&freq[i][0]>2)
            {
                res=max(res,freq[i][0]-2);
            }
        }
        return res==0?-1:res;
    }
};