class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        Arrays.sort(nums);
        int pt=0;
        List<Integer> res = new ArrayList<>();
        for(int i=nums[0];i<nums[nums.length-1];i++)
        {
            if(nums[pt]==i)
            {
                pt++;
            }
            else
            {
                res.add(i);
            }
        }
        return res;
    }
}