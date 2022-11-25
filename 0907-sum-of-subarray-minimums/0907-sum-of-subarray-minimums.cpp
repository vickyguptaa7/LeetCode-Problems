class Solution {
public:
    vector<int>nextSmallestLeft(vector<int>&arr)
    {
        int n=arr.size();
        stack<int>st;
        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty())
                result[i]=-1;
            else
                result[i]=st.top();
            st.push(i);
        }
        return result;
    }
    vector<int>nextSmallestRight(vector<int>&arr)
    {
        int n=arr.size();
        stack<int>st;
        vector<int>result(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
                result[i]=n;
            else
                result[i]=st.top();
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>left,right;
        left=nextSmallestLeft(arr);
        right=nextSmallestRight(arr);
        long long result=0;
        int mod=1e9+7,n=arr.size();
        for(long long i=0;i<n;i++)
        {
            result+=(i-left[i])*(right[i]-i)*arr[i];
            result%=mod;
        }
        return result;
    }
};