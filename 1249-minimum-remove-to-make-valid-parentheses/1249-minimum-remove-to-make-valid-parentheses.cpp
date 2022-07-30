class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a'&&s[i]<='z')continue;
            if(!st.empty()&&s[i]==')'&&st.top().first=='(')
            {
                st.pop();
            }
            else
            {
                st.push({s[i],i});
            }
        }
        string result;
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty()&&st.top().second==i)
            {
                st.pop();
                continue;
            }
            else
            {
                result+=s[i];
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};