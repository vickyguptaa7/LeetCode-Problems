class Solution {
public:
    
    string backSpace(string s)
    {
        string ans;
        for(auto x:s)
        {
            if(x=='#')
            {
                if(!ans.empty())
                    ans.pop_back();
            }
            else
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int it1=0,it2=0;
        while(it1<s.size()&&it2<t.size())
        {
            if(s[it1]!='#'&&t[it2]!='#')
            {
                
                if(s[it1]!=t[it2])
                    return false;
                it1++;
                it2++;
                continue;
            }
            int cntr=1;
            while(it1<s.size())
            {
                cntr+=(s[it1]=='#')?1:-1;
                if(cntr>0)
                {
                    it1++;
                    continue;
                }
                else 
                    break;
                    
            }
            cntr=1;
            while(it2<t.size())
            {
                cntr+=(t[it2]=='#')?1:-1;
                if(cntr>0)
                {
                    it2++;
                    continue;
                }
                else 
                    break;
                
            }
        }
        int cntr=1;
            while(it1<s.size())
            {
                cntr+=(s[it1]=='#')?1:-1;
                if(cntr>0)
                {
                    it1++;
                    continue;
                }
                else 
                    break;
                    
            }
            cntr=1;
            while(it2<t.size())
            {
                cntr+=(t[it2]=='#')?1:-1;
                if(cntr>0)
                {
                    it2++;
                    continue;
                }
                else 
                    break;
                
            }
        if(it1<s.size()||it2<t.size())
            return false;
        return true;
    }
};