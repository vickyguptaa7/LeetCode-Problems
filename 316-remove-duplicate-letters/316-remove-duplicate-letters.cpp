class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>freq;
        for(auto &x:s)
        {
            freq[x]++;
        }
        stack<char>st;
        
        unordered_set<char>uset;
        
        for(int i=0;i<s.size();i++)
        {
            if(uset.find(s[i])!=uset.end())
            {
                freq[s[i]]--;
                continue;
            }
                while(!st.empty()&&s[i]<=st.top()&&freq[st.top()]>0)
                {
                    uset.erase(st.top());
                    st.pop();
                }

                st.push(s[i]);
                freq[s[i]]--;
                uset.insert(s[i]);
        }
        string ans;
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};