class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<int>nextSLeft(n,0),nextSRight(n,0);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty())
                nextSLeft[i]=-1;
            else 
                nextSLeft[i]=st.top();
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty())
                nextSRight[i]=n;
            else 
                nextSRight[i]=st.top();
            st.push(i);
        }
        
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int size=nextSRight[i]-nextSLeft[i]-1;
            if(nums[i]>(threshold/(long double)size))
            {
                return size;
            }
        }
        return ans;
    }
};