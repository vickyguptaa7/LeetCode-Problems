class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int it=0;
        for(int i=0;i<t.size();i++)
        {
            if(s[it]==t[i])
                it++;
        }
        return it==s.size();
    }
};