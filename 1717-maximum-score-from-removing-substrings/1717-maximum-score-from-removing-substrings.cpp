class Solution {
public:
    
    int helper(string s,char a,char b,int x,int y)
    {
        stack<char>st;
        int cost=0;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty()&&s[i]==b&&st.top()==a)
            {
                st.pop();
                cost+=x;
            }
            else
            {
                st.push(s[i]);
            }
        }
        string str;
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        for(int i=0;i<str.size();i++)
        {
            if(!st.empty()&&str[i]==a&&st.top()==b)
            {
                st.pop();
                cost+=y;
            }
            else
            {
                st.push(str[i]);
            }
        }
        return cost;
    }
    
    int maximumGain(string s, int x, int y) {
        return max(helper(s,'a','b',x,y),helper(s,'b','a',y,x));
    }
};