class Solution {
    public boolean canJump(int[] nums) {
        int reach=nums[0];
        for(int i=1;i<nums.length;i++)
        {
            if(reach==0)
                return false;
            reach--;
            reach=Math.max(reach,nums[i]);
        }
        return true;
    }
}