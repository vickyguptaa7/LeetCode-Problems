class Solution {
    
    vector<int> findNextSmallLeft(vector<int>&arr)
    {
        vector<int>temp;
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
                temp.push_back(st.top());
            else
                temp.push_back(-1);
            st.push(i);
        }
        return temp;
    }
    
    vector<int> findNextSmallRight(vector<int>&arr)
    {
        vector<int>temp;
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
                temp.push_back(st.top());
            else
                temp.push_back(n);
            st.push(i);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
    int helper(vector<int>&arr)
    {
        vector<int>left=findNextSmallLeft(arr),
        right=findNextSmallRight(arr);
        
        int area=0;
        for(int i=0;i<arr.size();i++)
        {
            area=max(area,(right[i]-left[i]-1)*arr[i]);
        }
        return area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<int>arr(c,0);
        int area=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                arr[j]=(matrix[i][j]=='0')?0:arr[j]+1;
            }
            area=max(area,helper(arr));
        }
        return area;
    }
};