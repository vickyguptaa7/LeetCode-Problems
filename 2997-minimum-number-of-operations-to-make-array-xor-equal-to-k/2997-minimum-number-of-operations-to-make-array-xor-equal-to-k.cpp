class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>bit(30,0);
        for(auto num:nums)
        {
            for(int i=0;i<30;i++)
                if(num&(1<<i))
                    bit[i]++;
        }
        int oper=0;
        for(int i=0;i<30;i++)
        {
            if(k&(1<<i))
            {
                if(!(bit[i]&1))
                    oper++;
            }
            else
            {
                if(bit[i]&1)
                    oper++;
            }
        }
        return oper;
    }
};