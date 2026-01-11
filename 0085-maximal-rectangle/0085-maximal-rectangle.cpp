class Solution {
    public:
    
    vector<int> nextSmallRight(vector<int>&arr)
    {
        vector<int>res;
        stack<int>st;  
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                res.push_back(n);
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> nextSmallLeft(vector<int>&arr)
    {
        vector<int>res;
        stack<int>st;  
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }
        return res;
    }
    
    int histogramHelper(vector<int>&pre)
    {
        vector<int>nextSmallR=nextSmallRight(pre);
        vector<int>nextSmallL=nextSmallLeft(pre);
        int res=0;
        for(int i=0;i<pre.size();i++)
        {
            res=max(res,(nextSmallR[i]-nextSmallL[i]-1)*pre[i]);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>pre(m,0);
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pre[j]=matrix[i][j]=='0'?0:pre[j]+1;
            }

            res=max(res,histogramHelper(pre));
        }
        return res;
    }
};