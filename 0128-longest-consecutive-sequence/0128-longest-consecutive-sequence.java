class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer>st = new HashSet<>();
        Set<Integer>visit = new HashSet<>();
        
        for(int num:nums)
        {
            st.add(num);
        }
        int res=0;
        for(int num:nums)
        {
            if(st.contains(num-1)||visit.contains(num))
                continue;
            visit.add(num);
            int count=0,temp = num;
            while(st.contains(temp))
            {
                temp++;
                count++;
            }
            res=Math.max(res,count);
        }
        return res;
    }
}