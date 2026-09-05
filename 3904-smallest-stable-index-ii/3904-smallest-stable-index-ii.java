class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n =nums.length;
        int[] minarr = new int[n];
        minarr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            minarr[i]=Math.min(minarr[i+1],nums[i]);
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=Math.max(mx,nums[i]);
            if(k>=mx-minarr[i])
            {
                return i;
            }
        }
        return -1;
    }
}