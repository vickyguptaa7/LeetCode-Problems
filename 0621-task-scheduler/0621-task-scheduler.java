class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq=new int[26];
        for(char task:tasks)
        {
            freq[task-'A']++;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int num:freq)
        {
            if(num!=0)
                pq.add(num);
        }

        int res=0;
        int[] temp = new int[n+1];
        while(pq.size()>0)
        {
            int len=Math.min(pq.size(),n+1);
            for(int i=0;i<len;i++)
            {
                temp[i]=pq.peek();
                pq.poll();
            }
            boolean isZero = temp[0]==1;
            for(int i=0;i<len;i++)
            {
                if(temp[i]==1)continue;
                pq.add(temp[i]-1);
            }
            res+=len;
            if(!isZero)
            {
                res+=n+1-len;
            }
        }
        return res;
    }
}