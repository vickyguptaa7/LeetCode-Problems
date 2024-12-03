class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder res=new StringBuilder();
        int sindx=0;
        for(int i=0;i<s.length();i++)
        {
            if(sindx<spaces.length&&spaces[sindx]==i)
            {
                sindx++;
                res.append(' ');
            }
            res.append(s.charAt(i));
        }
        return res.toString();
    }
}