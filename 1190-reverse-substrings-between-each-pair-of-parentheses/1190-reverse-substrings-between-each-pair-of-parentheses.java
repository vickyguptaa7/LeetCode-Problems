class Solution {
    public String reverseParentheses(String s) {
        Stack<String>st=new Stack<>();
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==')')
            {
                String newStr="";
                while(!st.peek().equals("("))
                {
                    newStr+=new StringBuilder(st.pop()).reverse().toString();
                }
                st.pop();
                st.push(newStr);
            }
            else
            {
                st.push(s.substring(i,i+1));
            }
        }
        String newStr="";
        while(!st.empty())
        {
            newStr+=new StringBuilder(st.pop()).reverse().toString();;
        }
        return new StringBuilder(newStr).reverse().toString();
    }
}