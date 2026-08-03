class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq=new int[26];
        int mx=0,cnt=0;
        for(char task:tasks)
        {
            freq[task-'A']++;
            mx=Math.max(mx,freq[task-'A']);
        }
        for(int f:freq)cnt+=(f==mx)?1:0;
        int space = (mx-1)*(n);
        int left = tasks.length-mx-space-cnt+1;
        
        int res = space + mx + (cnt-1);
        if(left<=0)
        {
            return res;
        }
        else
        {
            return res+left;
        }
    }
}