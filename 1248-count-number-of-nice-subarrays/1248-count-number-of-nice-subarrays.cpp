class Solution {
    
    int helper(vector<int>&nums,int k)
    {
        int tail=0,head=-1,n=nums.size(),oddCnt=0;
        int ans=0;
        while(tail<n)
        {
            while(head+1<n&&((nums[head+1]&1)+oddCnt)<=k)
            {
                head++;
                oddCnt+=nums[head]&1;
            }
            ans+=head-tail+1;
            
            if(head<tail)
            {
                head=tail;
            }
            else
            {
                oddCnt-=nums[tail]&1;
            }
            tail++;
        }
        return ans;
    }
    
public:    
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};