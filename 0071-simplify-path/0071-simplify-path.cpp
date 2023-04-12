class Solution
{
    public:
        string simplifyPath(string path)
        {
            vector<string> st;
            string curr;
            path += "/";
            for (int i = 0; i < path.size(); i++)
            {
                if (path[i] == '/')
                {
                    if (curr.empty() || curr == ".")
                    {
                        curr = "";
                        continue;
                    }
                    if (curr == "..")
                    {
                        if (!st.empty())
                            st.pop_back();
                        curr = "";
                        continue;
                    }
                    st.push_back(curr);
                    curr = "";
                }
                else
                {
                    curr += path[i];
                }
            }
            string result;
            for (auto x: st)
            {
                result += "/" + x;
            }
            return result.empty() ? "/" : result;
        }
};