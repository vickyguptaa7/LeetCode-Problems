class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<int>average(n,-1);
        if(2*k+1>n)
            return average;
        
        long long sum=0;
        
        // for left most k ans will be -1
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
            average[i]=-1;
        }
        for(int i=k;i<n&&i<2*k+1;i++)
        {
            sum+=nums[i];
        }
        for(int i=k;i<n-k;i++)
        {
            average[i]=sum/(2*k+1ll);
            sum-=nums[i-k];
            if(i+k+1<n)
                sum+=nums[i+k+1];
        }
        // for right most k ans will be -1
        for(int i=n-k;i<n;i++)
        {
            average[i]=-1;
        }
        return average;
    }
};