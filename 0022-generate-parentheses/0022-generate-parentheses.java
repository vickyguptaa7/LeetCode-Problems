class Solution {

    public void helper(int left,int right, StringBuilder state, List<String> res)
    {
        if(right==0)
        {
            res.add(state.toString());
            return;
        }
        if(left>0)
        {
            state.append('(');
            helper(left-1,right,state,res);
            state.deleteCharAt(state.length()-1);
        } 
        if(left<right)
        {
            state.append(')');
            helper(left,right-1,state,res);
            state.deleteCharAt(state.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        helper(n,n,new StringBuilder(""),res);
        return res;
    }
}