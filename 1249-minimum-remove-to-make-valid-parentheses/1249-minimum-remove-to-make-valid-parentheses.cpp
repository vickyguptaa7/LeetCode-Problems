class Solution {
public:
    void breverse(string &s)
    {
        for(auto &x:s)
        {
            if(x=='(')
            {
                x=')';
            }
            else if(x==')')
            {
                x='(';
            }
        }
    }
    string removeInvalid(string s)
    {
        int left=0,right=0;
        string answer;
        int n=s.length();
        for(auto &x:s)
        {
            if(x=='(')
            {
                left++;
            }
            else if(x==')')
            {
                if(left>0)left--;
                else
                {
                    right++;
                    continue;
                }
            }
            answer+=x;
        }
        return answer;
    }
    string minRemoveToMakeValid(string s) {
        string answer=removeInvalid(s);
        breverse(answer);
        reverse(answer.begin(),answer.end());
        string res=removeInvalid(answer);
        reverse(res.begin(),res.end());
        breverse(res);
        return res;
    }
};
/*
"((()()("
*/