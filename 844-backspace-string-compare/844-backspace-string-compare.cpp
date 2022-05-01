class Solution {
public:
    string backSpace(string s)
    {
        string res;
        int back=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='#')back++;
            else 
            {
                if(back>0)
                {
                    back--;
                }
                else
                {
                    res=s[i]+res;
                }
            }
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {

        return backSpace(s)==backSpace(t);
        
    }
};