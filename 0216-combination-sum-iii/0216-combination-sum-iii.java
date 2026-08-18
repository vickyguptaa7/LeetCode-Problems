class Solution {

    private void helper(int lvl, int k,int n, List<Integer> temp,List<List<Integer>> res)
    {
        if(lvl>9||k==0)
        {
            if(n==0&&k==0) 
                res.add(new ArrayList<>(temp));
            return;
        }
        helper(lvl+1,k,n,temp,res);
        if(lvl>n)   return;
        temp.add(lvl);
        helper(lvl+1,k-1,n-lvl,temp,res);
        temp.remove(temp.size()-1);
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(1,k,n,temp,res);
        return res;
    }
}