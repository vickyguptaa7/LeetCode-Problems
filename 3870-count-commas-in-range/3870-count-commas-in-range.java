class Solution {
    public int countCommas(int n) {
        if(n<1000)
        {
            return 0;
        }
        else if(n>99999)
        {
            return n - 999;
        }
        else
        {
            return (n - 99999) + (99999 - 999);
        }
    }
}