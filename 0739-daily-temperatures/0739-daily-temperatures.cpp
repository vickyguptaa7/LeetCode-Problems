class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n=temp.size();
        vector<int>result(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&temp[st.top()]<=temp[i])
            {
                st.pop();
            }
            if(!st.empty())
                result[i]=st.top()-i;
            st.push(i);
        }
        return result;
    }
};