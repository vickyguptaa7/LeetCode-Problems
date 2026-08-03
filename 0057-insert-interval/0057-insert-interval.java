class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> temp = new ArrayList<>();
        int pt=0,strt=0;
        boolean isAdded=false;
        if(intervals.length>0&&newInterval[0]>intervals[0][1])
        {
            strt=1;
            temp.add(intervals[0]);
        }
        else
        {
            isAdded=true;
            temp.add(newInterval);
        }
        for(int i=strt;i<intervals.length;i++)
        {
            if(temp.get(pt)[1]>=intervals[i][0])
            {
                temp.get(pt)[0] = Math.min(temp.get(pt)[0], intervals[i][0]);
                temp.get(pt)[1] = Math.max(temp.get(pt)[1], intervals[i][1]);
            }
            else
            {
                if(!isAdded && (newInterval[0]<=intervals[i][1]))
                {
                    temp.add(newInterval);
                    isAdded=true;
                    pt++;
                    i--;
                    continue;
                }
                temp.add(intervals[i]);
                pt++;
            }
        }
        if(!isAdded)
        {
            if(newInterval[0]<=temp.get(pt)[1])
            {
                temp.get(pt)[0] = Math.min(temp.get(pt)[0], newInterval[0]);
                temp.get(pt)[1] = Math.max(temp.get(pt)[1], newInterval[1]);
            }
            else
            {
                temp.add(newInterval);
            }
        }

        return temp.toArray(new int[0][]);
    }
}