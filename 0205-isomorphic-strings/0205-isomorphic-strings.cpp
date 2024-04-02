class Solution {
public:
    
    bool helper(string s, string t) {
        vector<int>temp(256,-1);
        for(int i=0;i<s.size();i++)
        {
            if(temp[s[i]]==-1)
            {
                temp[s[i]]=t[i];
            }
            else if(temp[s[i]]!=t[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return helper(s,t)&&helper(t,s);
    }
};