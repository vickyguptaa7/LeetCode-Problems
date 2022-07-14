class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty()&&st.top()>num[i]&&k)
            {
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        
        while(k>0)
        {
            k--;
            st.pop();
        }
        
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        while(!ans.empty()&&ans.front()=='0')ans=ans.substr(1);
        if(ans.empty())ans="0";
        return ans;
    }
};