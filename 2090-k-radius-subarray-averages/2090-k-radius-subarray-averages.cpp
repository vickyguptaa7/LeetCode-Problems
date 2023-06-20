class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        
        // prefix sum
        vector<long long>preSum(n,0);
        preSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            preSum[i]=preSum[i-1]+nums[i];
        }
        
        vector<int>average(n,0);
        for(int i=0;i<n;i++)
        {
            // in left or right less than k so -1 
            if(i-k<0||i+k>=n)
            {
                average[i]=-1;
                continue;
            }
            
            long long sum=preSum[i+k];
            if(i-k!=0)
                sum-=preSum[i-k-1];
            sum/=(2*k+1ll);
            average[i]=sum;
        }
        return average;
    }
};