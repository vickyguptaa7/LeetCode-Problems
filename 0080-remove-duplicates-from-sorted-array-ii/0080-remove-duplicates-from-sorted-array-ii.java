class Solution {
    public int removeDuplicates(int[] nums) {
        int len=-1;
        for(int i=0;i<nums.length;i++)
        {
            int j=i+1;
            while(j<nums.length&&nums[i]==nums[j])
            {
                j++;
            }
            len++;
            nums[len]=nums[i];
            if(j-i>1)
            {
                len++;
                nums[len]=nums[i];
            }
            i=j-1;
        }
        return len+1;
    }
}