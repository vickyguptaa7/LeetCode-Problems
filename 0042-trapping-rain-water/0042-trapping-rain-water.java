class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] leftGreater = new int[n];
        for(int i=0;i<n;i++)
            leftGreater[i]=Math.max(height[i],i==0?0:leftGreater[i-1]);
        int[] rightGreater = new int[n];
        for(int i=n-1;i>=0;i--)
            rightGreater[i]=Math.max(height[i],i==n-1?0:rightGreater[i+1]);
        
        int res=0;
        for(int i=1;i<n-1;i++)
        {
            res+=Math.max(Math.min(leftGreater[i],rightGreater[i])-height[i],0);
        }
        return res;
    }
}