class Solution {
    public int jump(int[] nums) {
        if(nums.length==1)
            return 0;
        int reach=nums[0],max_reach=nums[0],step=1;
        for(int i=1;i<nums.length;i++)
        {
            if(reach==0)
            {
                step++;
                reach=max_reach;
            }
            reach--;
            max_reach=Math.max(max_reach-1,nums[i]);
        }
        return step;
    }
}