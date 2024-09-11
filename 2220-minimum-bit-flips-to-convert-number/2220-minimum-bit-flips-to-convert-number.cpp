class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cntr=0;
        for(int i=0;i<30;i++)
        {
            cntr+=(start&(1<<i))!=(goal&(1<<i));
        }
        return cntr;
    }
};