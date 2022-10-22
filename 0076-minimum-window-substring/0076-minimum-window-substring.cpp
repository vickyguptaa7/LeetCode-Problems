class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())
            return "";
        
        unordered_map<char,int>srr,trr;
        for(auto x:t)trr[x]++;
        int prev=0;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(trr.count(s[i]))
            {
                srr[s[i]]++;
            }
            if(isMatched(srr,trr))
            {
                do
                {
                    if(result.size()>i-prev+1||result=="")
                        result=s.substr(prev,i-prev+1);
                    srr[s[prev]]--;
                    if(srr[s[prev]]==0)
                    {
                        srr.erase(s[prev]);
                    }
                    prev++;
                }while(isMatched(srr,trr));
            }
        }
        return result;
    }
    bool isMatched(unordered_map<char,int>&srr,unordered_map<char,int>&trr)
    {
        for(auto x:trr)
        {
            if(!srr.count(x.first)||srr[x.first]<x.second)
            {
                return false;
            }
        }
        return true;
    }
};