class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();
        int mx=1,left=-1,curr=0;
        while(curr<nums.length)
        {
            while(mp.getOrDefault(nums[curr],0)==k)
            {
                left++;
                mp.put(nums[left],mp.get(nums[left])-1);
            }
            mp.put(nums[curr],mp.getOrDefault(nums[curr],0)+1);
            mx=Math.max(mx,curr-left);
            curr++;
        }
        return mx;
    }
}