class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty()&&s[i]=='c')
            {
                int bc=0;
                while(!st.empty()&&st.top()=='b')
                {
                    st.pop();
                    bc++;
                }
                if(bc!=1)return false;
                if(st.empty())return false;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        if(!st.empty())return false;
        return true;
    }
};