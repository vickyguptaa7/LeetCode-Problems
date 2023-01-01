class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>mmp;
        int iter=0;
        string word;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '||i+1==s.size())
            {
                if(i+1==s.size())
                    word+=s[i];
                if(iter==pattern.size())
                    return false;
                if(mmp.count(pattern[iter])&&mmp[pattern[iter]]!=word)
                {
                    return false;
                }
                else
                {
                    mmp[pattern[iter]]=word;
                }
                word="";
                iter++;
            }
            else
            {
                word+=s[i];
            }
        }
        if(iter<pattern.size())
            return false;
        set<string>oset;
        for(auto x:mmp)
        {
            oset.insert(x.second);
        }
        return oset.size()==mmp.size();
    }
};