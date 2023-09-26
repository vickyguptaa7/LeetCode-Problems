class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>freq;
        for(auto ch:s)freq[ch]++;
        stack<char>st;
        int taken=0;
        for(int i=0;i<s.size();i++)
        {
            if(taken&(1<<(s[i]-'a')))
            {
                freq[s[i]]--;
                continue;
            }
            while(!st.empty()&&s[i]<=st.top()&&freq[st.top()]>0)
            {
                taken=(taken^(1<<(st.top()-'a')));
                st.pop();
            }
            st.push(s[i]);
            taken|=(1<<(s[i]-'a'));
            freq[s[i]]--;
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