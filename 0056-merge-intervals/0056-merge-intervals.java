class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->{
            if(a[0]!=b[0])
                return Integer.compare(a[0],b[0]);
            return Integer.compare(a[1],b[1]);
        });
        int pt=0;
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0]);
        for(int i=1;i<intervals.length;i++)
        {
            if(res.get(pt)[1]>=intervals[i][0])
            {
                res.get(pt)[0]=Math.min(res.get(pt)[0],intervals[i][0]);
                res.get(pt)[1]=Math.max(res.get(pt)[1],intervals[i][1]);
            }
            else
            {
                res.add(intervals[i]);
                pt++;
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}