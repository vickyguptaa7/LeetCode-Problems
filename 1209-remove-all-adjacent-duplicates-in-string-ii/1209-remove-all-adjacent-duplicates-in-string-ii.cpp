class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char>st;
        map<char,int>freq;
        queue<char>helper;
        for(int i=0;i<s.size();i++)
        {
            st.push(s[i]);
            freq[s[i]]++;
            helper.push(s[i]);
            if(st.size()>=k)
            {
                if(freq.size()==1)
                {
                    int temp=k;
                    while(temp--)
                    {
                        st.pop();
                    }
                    freq.erase(s[i]);
                    while(!helper.empty())helper.pop();
                    if(!st.empty())
                    {
                        stack<char>tpp;
                        int temp=k-1;
                        while(!st.empty()&&temp--)
                        {
                            freq[st.top()]++;
                            tpp.push(st.top());
                            st.pop();
                        }
                        while(!tpp.empty())
                        {
                            helper.push(tpp.top());
                            st.push(tpp.top());
                            tpp.pop();
                        }
                    }
                }
                else 
                {
                    freq[helper.front()]--;
                    if(freq[helper.front()]==0)
                    {
                        freq.erase(helper.front());
                    }
                    helper.pop();
                }
            }
        }
        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};