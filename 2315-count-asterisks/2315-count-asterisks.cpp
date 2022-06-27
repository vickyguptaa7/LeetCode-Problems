class Solution {
public:
    int countAsterisks(string s) {
        stack<char>st;
        bool isStart=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='|')
            {
                if(isStart)
                {
                    while(st.top()!='|')
                        st.pop();
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
                isStart=!isStart;
            }
            else
            {
                st.push(s[i]);
            }
        }
        int ans=0;
        while(!st.empty())
        {
            if(st.top()=='*')ans++;
            st.pop();
        }
        return ans;
    }
};