class Solution {
public:
    int maxVowels(string s, int k) {
        int vCnt=0,vmaxCnt=0;
        vector<bool>alpha(26,0);
        alpha['a'-'a']=1;
        alpha['e'-'a']=1;
        alpha['i'-'a']=1;
        alpha['o'-'a']=1;
        alpha['u'-'a']=1;
        for(int i=0;i<s.size();i++)
        {
            if(alpha[s[i]-'a'])
            {
                vCnt++;
            }
            if(i>=k&&alpha[s[i-k]-'a'])
            {
                vCnt--;
            }
            vmaxCnt=max(vCnt,vmaxCnt);
        }
        return vmaxCnt;
    }
};