class Solution {
    public int trailingZeroes(int n) {
        int five=0,num=5;
        for(int i=1;i<=10;i++)
        {
            five+=(n/num);
            num*=5;
        }
        return five;
    }
}