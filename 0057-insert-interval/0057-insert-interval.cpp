class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        stack<vector<int>>st;
        bool isInserted=false;
        int n=intervals.size();
        for(int i=n-1;i>=0;i--)
        {
            if(intervals[i][0]>newInterval[0])
            {
                st.push(intervals[i]);
            }
            else
            {
                if(!isInserted)
                {
                    st.push(newInterval);
                    isInserted=true;
                }
                st.push(intervals[i]);
            }
        }
        if(!isInserted)
            st.push(newInterval);
        
        vector<vector<int>>result;
        while(st.size()!=1)
        {
            vector<int>itv1=st.top();
            st.pop();
            vector<int>itv2=st.top();
            st.pop();
            if(itv1[1]<itv2[0])
            {
                result.push_back(itv1);
                st.push(itv2);
            }
            else
            {
                st.push({min(itv1[0],itv2[0]),max(itv2[1],itv1[1])});
            }
        }
        result.push_back(st.top());
        return result;
    }
};