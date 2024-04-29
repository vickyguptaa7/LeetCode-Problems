class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int oper=0;
        for(int i=0;i<21;i++)
        {
            int bcnt=0;
            for(int j=0;j<nums.size();j++)
            {
                bcnt+=(1&(nums[j]>>i));
            }
            if(1&(k>>i))
            {
                oper+=(bcnt&1)?0:1;
            }
            else
            {
                oper+=(bcnt&1)?1:0;
            }
        }
        return oper;
    }
};