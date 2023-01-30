class Solution {
public:
    
    vector<int>nextSmallerToRight(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>arr(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                arr[i]=st.top();
            }
            st.push(i);
        }
        return arr;
    }
    vector<int>nextSmallerToLeft(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>arr(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                arr[i]=st.top();
            }
            st.push(i);
        }
        return arr;
    }
    vector<long long> prefixSum(vector<int>&nums)
    {
        int n=nums.size();
        vector<long long>preSum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            preSum[i]=preSum[i-1]+nums[i-1];
        }
        return preSum;
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextSmallRight=nextSmallerToRight(nums);
        vector<int>nextSmallLeft=nextSmallerToLeft(nums);
        vector<long long>preSum=prefixSum(nums);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,nums[i]*(preSum[nextSmallRight[i]]-preSum[nextSmallLeft[i]+1]));
        }
        int mod=1e9+7;
        return ans%mod;
   
    }
};