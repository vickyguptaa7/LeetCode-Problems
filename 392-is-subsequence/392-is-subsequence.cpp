class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen=s.size(),tlen=t.size();
        int i,j;
        for(i=0,j=0;i<slen&&j<tlen;j++)
        {
            if(s[i]==t[j])
            {
                i++;
            }
        }
        if(i==slen)return true;
        return false;
    }
};