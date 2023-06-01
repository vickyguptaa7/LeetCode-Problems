class Solution {
public:
    vector<int>findNextSmallToRight(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>nextSmall(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
                nextSmall[i]=st.top();
            else 
                nextSmall[i]=n;
            st.push(i);
        }
        return nextSmall;
    }
    vector<int>findNextSmallToLeft(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>nextSmall(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
                nextSmall[i]=st.top();
            else 
                nextSmall[i]=-1;
            st.push(i);
        }
        return nextSmall;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextSmallToLeft=findNextSmallToLeft(heights);
        vector<int>nextSmallToRight=findNextSmallToRight(heights);
        int largestRectangle=0;
        for(int i=0;i<heights.size();i++)
        {
            int length=nextSmallToRight[i]-nextSmallToLeft[i]-1;
            cout<<length<<"\n";
            largestRectangle=max(largestRectangle,length*heights[i]);
        }
        return largestRectangle;
    }
};