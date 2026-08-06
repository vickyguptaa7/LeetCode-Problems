class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int[] res = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() > 0 && st.peek() <= nums[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                res[i] = -1;
            }
            else
            {
                res[i] = st.peek();
            }
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() > 0 && st.peek() <= nums[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                res[i] = -1;
            }
            else
            {
                res[i] = st.peek();
            }
            st.push(nums[i]);
        }
        return res;
    }
}