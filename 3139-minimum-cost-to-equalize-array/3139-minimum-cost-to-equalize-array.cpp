class Solution {
public:
    
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int mod=1e9+7;
        long long ans=2e18;
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        int n=nums.size();
        if(cost1*2<=cost2)
        {
            return ((mx*1ll*n-sum)*cost1)%mod;
        }
        for(int i=mx;i<=2*mx;i++)
        {
            long long total_oper=i*1ll*n-sum;
            int max_bar=i-mn;
            long long curr=0;
            
            // checking of largest bar is greater than rest of bar sum
            if(max_bar>=total_oper-max_bar)
            {
                long long extra=(max_bar-(total_oper-max_bar));
                curr+=extra*cost1;
                total_oper-=extra;
            }
            
            // adding odd
            if(total_oper&1)
            {
                total_oper--;
                curr+=cost1;
            }
            curr+=(total_oper/2)*cost2;
            ans=min(ans,curr);
        }
        
        
        return ans%mod;
    }
};