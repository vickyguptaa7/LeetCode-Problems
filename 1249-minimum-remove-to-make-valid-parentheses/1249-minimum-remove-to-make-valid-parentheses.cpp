class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')st.push(i);
            else if(s[i]==')')
            {
                if(st.empty())s[i]='@';
                else st.pop();
            }
        }
        while(!st.empty())
        {
            s[st.top()]='@';
            st.pop();
        }
        string res;
        for(auto &x:s)
        {
            if(x!='@')res+=x;
        }
        return res;
    }
};
/*
"((()()("

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
*/