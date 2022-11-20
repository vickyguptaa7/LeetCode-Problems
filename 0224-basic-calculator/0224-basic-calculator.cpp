class Solution
{
    public:
     int calculate(string s)
{
    stack<string> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            continue;
        else if (s[i] == ')')
        {
            while (true)
            {
                string n1 = st.top();
                st.pop();
                string op = st.top();
                st.pop();
                if (op == "(")
                {
                    st.push(n1);
                    break;
                }
                string n2 = st.top();
                st.pop();
                if (n2 == "(")
                {
                    if (n1[0] == '-' && op == "-")
                    {
                        st.push(n1.substr(1));
                    }
                    else
                        st.push(op + n1);
                    break;
                }
                int num1 = stoi(n1), num2 = stoi(n2), res = 0;
                if (op == "-")
                    num1 = -num1;
                if (!st.empty() && st.top() == "-")
                {
                    st.pop();
                    st.push("+");
                    num2 = -num2;
                }
                res = num2 + num1;
                st.push(to_string(res));
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            string num;
            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                i++;
            }
            i--;
            st.push(num);
        }
        else
        {
            string op;
            op += s[i];
            st.push(op);
        }
    }
    while (st.size() > 2)
    {
        string n1 = st.top();
        st.pop();
        string op = st.top();
        st.pop();
        string n2 = st.top();
        st.pop();
        int num1 = stoi(n1), num2 = stoi(n2), res = 0;
        if (op == "-")
            num1 = -num1;
        if (!st.empty() && st.top() == "-")
        {
            st.pop();
            st.push("+");
            num2 = -num2;
        }
        res = num2 + num1;
        st.push(to_string(res));
    }
    if (st.size() == 1)
        return stoi(st.top());
    string ans = st.top();
    st.pop();
    if (ans[0] == '-')
    {
        if (st.top() == "-")
            return -stoi(ans);
        else
            return stoi(ans);
    }
    return stoi(st.top() + ans);
}
};