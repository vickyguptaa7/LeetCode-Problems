class Solution {

    private void helper(int lvl, int target, int[] candidates,List<Integer> temp, List<List<Integer>>res)
    {
        if(lvl==candidates.length)
        {
            if(target==0)
                res.add(new ArrayList<>(temp));
            return;
        }
        helper(lvl+1,target,candidates,temp,res);
        if(target<candidates[lvl])
        {
            return;
        }
        temp.add(candidates[lvl]);
        helper(lvl,target-candidates[lvl],candidates,temp,res);
        temp.remove(temp.size()-1);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(0, target, candidates, temp, res);
        return res;
    }
}