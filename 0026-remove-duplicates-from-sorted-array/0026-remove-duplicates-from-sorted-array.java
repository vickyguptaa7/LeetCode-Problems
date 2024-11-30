class Solution {
    public int removeDuplicates(int[] nums) {
        int[] freq=new int[204];
        for(int i=0;i<nums.length;i++)
        {
            freq[nums[i]+101]++;
        }
        
        int len=0;
        for(int i=0;i<freq.length;i++)
        {
            if(freq[i]!=0)
            {
                nums[len]=i-101;
                len++;
            }
        }
        return len;
    }
}