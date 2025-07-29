class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int size=nums.length;
        int[] ans = new int[size];
        int[] bits = new int[31];
        
        for(int i=0;i<bits.length;i++)
            bits[i]=-1;
        
        for(int i=size-1;i>=0;i--)
        {
            ans[i]=i;
            for(int j=0;j<31;j++)
            {
                if((nums[i]&(1<<j))>0)
                {
                    bits[j]=i;
                }
                ans[i]=Math.max(ans[i],bits[j]);
            }
            ans[i]=ans[i]-i+1;
        }
        return ans;
    }
}