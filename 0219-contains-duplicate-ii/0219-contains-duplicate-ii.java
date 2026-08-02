class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,List<Integer>> mp = new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            if(!mp.containsKey(nums[i]))
            {
                mp.put(nums[i],new ArrayList<>());
            }
            mp.get(nums[i]).add(i);
        }
        for(Map.Entry<Integer,List<Integer>> entry : mp.entrySet())
        {
            for(int i=1;i<entry.getValue().size();i++)
            {
                if(entry.getValue().get(i)-entry.getValue().get(i-1)<=k)
                    return true;
            }
        }
        return false;
    }
}