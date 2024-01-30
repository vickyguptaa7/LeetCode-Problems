class Solution {
public:
    
    void helper(string s,stack<int>&st)
    {
        if(s=="*"||s=="+"||s=="/"||s=="-")
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(s=="*")
            {
                st.push(a*b);
            }
            else if(s=="+")
            {
                st.push(a+b);
            }
            else if(s=="-")
            {
                st.push(b-a);
            }
            else 
                st.push(b/a);
            
        }
        else 
            st.push(stoi(s));
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            helper(tokens[i],st);
        }
        return st.top();
    }
};