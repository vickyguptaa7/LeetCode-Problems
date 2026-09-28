class Solution {
    public int maxDepth(String s) {
        int left=0,mx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='(')left++;
            else if(s.charAt(i)==')')left--;
            mx=Math.max(left,mx);
        }
        return mx;
    }
}