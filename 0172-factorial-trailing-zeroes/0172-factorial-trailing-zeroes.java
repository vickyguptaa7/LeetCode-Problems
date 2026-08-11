class Solution {
    public int trailingZeroes(int n) {
        int five=0;
        for(int i=5;i<=n;i+=5)
        {
            int temp=i;
            while(temp%5==0)
            {
                temp/=5;
                five++;
            }
        }
        return five;
    }
}