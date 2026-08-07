class Solution {
    public void sortColors(int[] nums) {
        int[] count = new int[3];
        for(int i=0;i<nums.length;i++)
        {
            count[nums[i]]++;
        }
        int baseIndex=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<count[i];j++)
            {
                nums[baseIndex+j]=i;
            }
            baseIndex+=count[i];
        }
    }
}