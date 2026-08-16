class Solution {
    public boolean stoneGameIX(int[] stones) {
        int zero_cnt=0,one_cnt=0,two_cnt=0;
        for(int i=0;i<stones.length;i++)
        {
            zero_cnt += stones[i]%3==0?1:0;
            one_cnt += stones[i]%3==1?1:0;
            two_cnt += stones[i]%3==2?1:0;
        }
        if(zero_cnt%2==0)
            return one_cnt>=1 && two_cnt>=1;
        return Math.abs(one_cnt-two_cnt)>2;
    }
}