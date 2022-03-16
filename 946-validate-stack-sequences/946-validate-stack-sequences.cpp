class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int iter=0,n=pushed.size();
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            while(!st.empty()&&st.top()==popped[iter])
            {
                st.pop();
                iter++;
            }
        }
        return st.empty();
    }
};