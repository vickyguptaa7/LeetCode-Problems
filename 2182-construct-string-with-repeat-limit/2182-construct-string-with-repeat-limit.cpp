class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        string res;
        while(!mp.empty())
        {
            auto it=mp.rbegin();
            for(int i=0;i<min(repeatLimit,it->second);i++)
            {
                res+=it->first;
            }
            if(it->second<=repeatLimit)
            {
                mp.erase(it->first);
            }
            else
            {
                mp[it->first]-=repeatLimit;
                if(mp.size()>1)
                {
                    it++;
                    res+=it->first;
                    if(mp[it->first]==1)
                    {
                        mp.erase(it->first);
                    }
                    else
                    {
                        mp[it->first]--;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
};