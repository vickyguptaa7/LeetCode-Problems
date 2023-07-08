class Solution
{
    public:
        string simplifyPath(string path)
        {
            vector<string> st;
            string curr;
            for (int i = 0; i < path.size(); i++)
            {
                if (path[i] == '/')
                {
                    if (curr == "..")
                    {
                        if (!st.empty())
                            st.pop_back();
                    }
                    else
                    {
                        if (!curr.empty() && curr != ".")
                            st.push_back(curr);
                    }
                    curr = "";
                }
                else
                {
                    curr += path[i];
                }
            }
            if (curr == "..")
            {
                if (!st.empty())
                    st.pop_back();
            }
            else
            {
                if (!curr.empty() && curr != ".")
                    st.push_back(curr);
            }
            string result = "";
            for (int i = 0; i < st.size(); i++)
            {
                result += "/";
                result += st[i];
            }
            return result.empty() ? "/" : result;
        }
};