class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        int combination = (1<<(nums.length));
        List<List<Integer>> res = new ArrayList<>();
        Set<List<Integer>> st = new HashSet<>();
        System.out.println(combination);
        for(int i=0;i<combination;i++)
        {
            List<Integer> intermediate = new ArrayList<>();
            for(int j=0;j<nums.length;j++)
            {
                if((i&(1<<j))>0)
                {
                    intermediate.add(nums[j]);
                }
            }
            Collections.sort(intermediate);
            if(!st.contains(intermediate))
            {
                res.add(intermediate);
                st.add(intermediate);
            }
        }
        return res;
    }
}