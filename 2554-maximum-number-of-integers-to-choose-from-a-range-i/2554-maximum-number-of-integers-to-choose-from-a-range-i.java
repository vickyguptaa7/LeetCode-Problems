class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Arrays.sort(banned);
        int count=0,indx=0;
        for(int i=1;i<=n;i++)
        {
            if(maxSum-i<0)
                break;
            if(indx<banned.length&&i>=banned[indx])
            {
                i-=i>banned[indx]?1:0;
                indx++;
                continue;
            }
            count++;
            maxSum-=i;
        }
        return count;
    }
}