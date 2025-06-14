class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num),t=to_string(num);
        char mnch='#',mxch='#';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='9'&&mxch=='#')
            {
                mxch=s[i];
                s[i]='9';
            }
            else if(s[i]==mxch)
            {
                s[i]='9';
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(t[i]!='0'&&mnch=='#')
            {
                mnch=t[i];
                t[i]='0';
            }
            else if(t[i]==mnch)
            {
                t[i]='0';
            }
        }

        return stoi(s)-stoi(t);
    }
};