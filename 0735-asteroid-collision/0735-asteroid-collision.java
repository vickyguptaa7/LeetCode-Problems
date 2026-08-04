class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for(int asteroid:asteroids)
        {
            if(asteroid<0)
            {
                while(st.size() > 0 && st.peek() > 0 && st.peek()+asteroid<0)
                {
                    st.pop();
                }
                if (st.size() > 0 && st.peek() + asteroid == 0)
                {
                    st.pop();
                }
                else if(st.isEmpty() || st.peek() < 0)
                    st.push(asteroid);
            }
            else
            {
                st.push(asteroid);
            }
        }

        return st.stream().mapToInt(Integer::intValue).toArray();
    }
}