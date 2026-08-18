class Solution {
    private void helper(int lvl, int target, int[] candidates, List<Integer>temp, List<List<Integer>> res)
    {
        if(lvl==candidates.length)
        {
            if(target==0)
                res.add(new ArrayList<>(temp));
            return;
        }
        int same=0;
        for(int i=lvl;i<candidates.length;i++)
        {
            if(candidates[lvl]!=candidates[i])break;
            same+=candidates[lvl]==candidates[i]?1:0;
        }
        helper(lvl+same,target,candidates,temp,res);
        for(int i=0;i<same;i++)
        {
            if(target<candidates[lvl]*(i+1))
                break;
            for(int j=0;j<=i;j++)
                temp.add(candidates[lvl]);
            helper(lvl+same,target-candidates[lvl]*(i+1),candidates,temp,res);
            for(int j=0;j<=i;j++)
                temp.remove(temp.size()-1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(0,target,candidates,temp,res);
        return res;
    }
}