class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')st.push(ans.size());
            else if(s[i]==')')
            {
                reverse(ans.begin()+st.top(),ans.end());
                st.pop();
            }
            else
                ans+=s[i];
        }
        return  ans;
    }
};