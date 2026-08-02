class Solution {
    public int majorityElement(int[] nums) {
        int count=0, ele=0;
        for(int i=0;i<nums.length;i++)
        {
            if(ele==nums[i])
            {
                count++;
            }
            else if(count==0)
            {
                ele = nums[i];
                count=1;
            }
            else
            {
                count--;
            }
        }
        return ele;
    }
}