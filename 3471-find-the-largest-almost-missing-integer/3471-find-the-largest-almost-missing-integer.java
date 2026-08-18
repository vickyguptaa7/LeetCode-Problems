class Solution {
    public int largestInteger(int[] nums, int k) {
        if(k==nums.length)
        {
            int mx=0;
            for(int i=0;i<nums.length;i++)mx=Math.max(mx,nums[i]);
            return mx;
        }
        if(k==1)
        {
            int[] freq = new int[51];
            for(int i=0;i<nums.length;i++)
            {
                freq[nums[i]]++;
            }
            for(int i=50;i>=0;i--)
                if(freq[i]==1)
                    return i;
            return -1;
        }
        int f1=0,f2=0;
        for(int i=0;i<nums.length;i++)
        {
            f1 += nums[i]==nums[0]?1:0;
            f2 += nums[i]==nums[nums.length-1]?1:0;
        }
        if(f1==1 && f2==1)
        {
            return nums[0]<nums[nums.length-1]?nums[nums.length-1]:nums[0];
        }
        if(f1==1)
            return nums[0];
        if(f2==1)
            return nums[nums.length-1];
        return -1;
    }
}