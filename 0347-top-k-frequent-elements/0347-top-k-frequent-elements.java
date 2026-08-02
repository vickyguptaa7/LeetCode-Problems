class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] freq = new int[20002];
        for(int num:nums)
        {
            freq[num+10000]++;
        }
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));
        
        for(int i=0;i<20002;i++)
        {
            if(freq[i]==0)continue;
            int[] cand = new int[2];
            cand[0]=freq[i];
            cand[1]=i-10000;
            maxHeap.add(cand);
        }
        int[] res = new int[k];
        for(int i=0;i<k;i++)
            res[i]=maxHeap.poll()[1];
        return res;
    }
}