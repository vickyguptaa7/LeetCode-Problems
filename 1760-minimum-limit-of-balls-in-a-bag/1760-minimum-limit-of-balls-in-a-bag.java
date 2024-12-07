class Solution {
    
    private boolean check(int[] nums,int maxOperations,int div)
    {
        for(int i=0;i<nums.length;i++)
        {
            maxOperations-=Math.ceil(nums[i]/(double)div)-1;
            if(maxOperations<0)
                return false;
        }
        return true;
    }
    
    public int minimumSize(int[] nums, int maxOperations) {
        int low=1,high=(int)1e9,ans=(int)1e9;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(nums,maxOperations,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
}