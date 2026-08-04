class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(int[] a,int[] b) ->{
            if(a[1]!=b[1])
                return Integer.compare(a[1],b[1]);
            return Integer.compare(a[0],b[0]);
        });
        long lastTrigger=-3000000000l;
        int arrows=0;
        for(int i=0;i<points.length;i++)
        {
            if(lastTrigger<points[i][0])
            {
                arrows++;
                lastTrigger=points[i][1];
            }
        }
        return arrows;
    }
}