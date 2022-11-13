class Solution
{
    public:
        void removeInvalidSpaces(string & s)
        {
            int strt = 0, findx = 0;
            while (s[findx] == ' ') findx++;
            for (int i = findx; i < s.size(); i++)
            {
                if (s[i] == ' ')
                {
                    while (i + 1 < s.size() && s[i + 1] == ' ') i++;
                    if (i + 1 != s.size())
                        s[strt++] = ' ';
                }
                else
                {
                    s[strt++] = s[i];
                }
            }
            s = s.substr(0, strt);
        }
    string reverseWords(string s)
    {
        removeInvalidSpaces(s);
        int strt = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                while (!st.empty())
                {
                    s[strt++] = st.top();
                    st.pop();
                }
                strt++;
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            s[strt++] = st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};