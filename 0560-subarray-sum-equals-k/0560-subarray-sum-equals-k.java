class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();
        int sum=0,res=0;
        mp.put(0,1);
        for(int i=0;i<nums.length;i++)
        {
            sum+=nums[i];
            res+=mp.getOrDefault(sum-k,0);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return res;
    }
}