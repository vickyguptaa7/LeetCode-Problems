class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bits(32,0);
        int result=0;
        for(int i=0;i<32;i++)
        {
            int bitcount=0;
            for(auto num:nums)
            {
                if((1<<i)&num)
                    bitcount++;
            }
            bitcount%=3;
            // two cases bitcount 0 or 1 there will be no case for bitcount to be 2
            result+=(bitcount<<i);
        }
        return result;
    }
};