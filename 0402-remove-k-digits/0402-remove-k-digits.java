class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        for(int i=0;i<num.length();i++)
        {
            while(st.size() > 0 && k > 0 && st.peek() > num.charAt(i))
            {
                st.pop();
                k--;
            }
            st.push(num.charAt(i));
        }
        StringBuilder temp = new StringBuilder();
        while(k>0)
        {
            k--;
            st.pop();
        }
        while(st.size()>0)
        {
            temp.append(st.pop());
        }
        temp = temp.reverse();
        StringBuilder res = new StringBuilder();
        boolean skip = true;
        for(int i=0;i<temp.length();i++)
        {
            if(temp.charAt(i)=='0' && skip)
            {
                continue;
            }
            else
            {
                skip = false;
            }
            res.append(temp.charAt(i));
        }
        if(res.length()==0)
            return "0";
        return res.toString();
    }
}