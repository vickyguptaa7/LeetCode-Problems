class Solution {
public:
    int findComplement(int num) {
        int temp=0,iter=0;
        while(num)
        {
            temp|=(num&1)?0:(1<<iter);
            num/=2;
            iter++;
        }
        return temp;
    }
};