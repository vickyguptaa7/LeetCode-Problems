class Solution {
    public int longestSubsequence(int[] nums) {
        int zero_cnt=0,xr=0;
        for(int i=0;i<nums.length;i++)
        {
            zero_cnt+=nums[i]==0?1:0;
            xr=(xr^nums[i]);
        }
        if(zero_cnt==nums.length)
            return 0;
        if(xr>0)
            return nums.length;
        return nums.length-1;
    }
}