class Solution {
public:
    
    void helper(int indx,string str,string &s,set<string>&sset,vector<string>&res)
    {
        if(indx==s.size())
        {
            res.push_back(str);
            return;
        }
        string word;
        for(int i=indx;i<s.size();i++)
        {
            word+=s[i];
            if(sset.count(word))
            {
                helper(i+1,str.empty()?word:str+" "+word,s,sset,res);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        set<string>sset(wordDict.begin(),wordDict.end());
        helper(0,"",s,sset,res);
        return res;
    }
};