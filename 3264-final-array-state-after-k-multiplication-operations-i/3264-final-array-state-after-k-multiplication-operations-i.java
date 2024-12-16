class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for(int i=0;i<k;i++)
        {
            int mn=0;
            for(int j=0;j<nums.length;j++)
            {
                if(nums[mn]>nums[j])
                {
                    mn=j;
                }
            }
            nums[mn]*=multiplier;
        }
        return nums;
    }
}