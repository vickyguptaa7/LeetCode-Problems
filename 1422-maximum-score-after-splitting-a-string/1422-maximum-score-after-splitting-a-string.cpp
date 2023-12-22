class Solution {
public:
    int maxScore(string s) {
        int oc=0,zc=0,mx=0;
        for(auto &ch:s)oc+=ch=='1';
        for(int i=0;i+1<s.size();i++)
        {
            oc-=s[i]=='1';
            zc+=s[i]=='0';
            mx=max(mx,oc+zc);
        }
        return mx;
    }
};