class Solution {

    //     public int myAtoi(String s) {
    //        // return f(s,0);
    //           if(s==null) return 0;

    //         s=s.trim();

    //         if(s.length()==0) return 0;

    //         int sign = +1;
    //         long ans = 0;
    //         if(s.charAt(0) == '-') sign = -1;

    //         int MAX = Integer.MAX_VALUE, MIN = Integer.MIN_VALUE;

    // 		// initiate the starting pointer
    //         int i = (s.charAt(0) == '+' || s.charAt(0) == '-') ? 1 : 0;

    //         while(i < s.length()) {
    //             if(s.charAt(i) == ' ' || !Character.isDigit(s.charAt(i))) break;
    //             ans = ans * 10 + s.charAt(i)-'0';
    //             // check the conditions
    //             if(sign == -1 && -1*ans < MIN) return MIN;
    //             if(sign == 1 && ans > MAX) return MAX;

    //             i++;
    //         }

    //         return (int)(sign*ans);
    //     }
    public int myAtoi(String s) {
        long ans = 0;
        s = s.trim();
        if (s.length() == 0) return 0;
        int i = ((s.charAt(0) == '+') || (s.charAt(0) == '-') ? 1 : 0);
        int sign = ((s.charAt(0) == '-') ? -1 : 1);
        while (i < s.length()) {
            if (s.charAt(i) == ' ' || !Character.isDigit(s.charAt(i))) break;
            if (Character.isDigit(s.charAt(i))) {
                ans = ans * 10 + (s.charAt(i) - '0');
            }
            i++;
            if (ans >= Integer.MAX_VALUE+(long)1 && sign==-1) {
                System.out.println("min\n");
                return Integer.MIN_VALUE;
            }
            if (ans >= Integer.MAX_VALUE &&sign==1) {
                return Integer.MAX_VALUE;
            }
        }
        ans *= sign;
        return (int) ans;
    }
}
