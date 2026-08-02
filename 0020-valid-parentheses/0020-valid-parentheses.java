class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s.charAt(i)=='('||s.charAt(i)=='['||s.charAt(i)=='{')
            {
                st.push(s.charAt(i));
            }
            else 
            {
                if(st.size()>0&&((st.peek()=='('&&s.charAt(i)==')')||(st.peek()=='['&&s.charAt(i)==']')||(st.peek()=='{'&&s.charAt(i)=='}')))
                    st.pop();
                else 
                    return false;
            }
        }
        return st.size()==0;
    }
}