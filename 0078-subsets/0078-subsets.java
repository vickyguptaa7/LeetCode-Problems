class Solution {

    private void helper(int indx,int[] nums,List<Integer> intermediate, List<List<Integer>> res)
    {
        if(indx==nums.length)
        {
            res.add(new ArrayList<>(intermediate));
            return;
        }
        helper(indx+1,nums,intermediate,res);
        intermediate.add(nums[indx]);
        helper(indx+1,nums,intermediate,res);
        intermediate.remove(intermediate.size()-1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        helper(0,nums, new ArrayList<>(),res);
        return res;
    }
}