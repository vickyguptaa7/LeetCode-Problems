class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i],it=0;
            while(num)
            {
                if(num&1)result=(result|(1<<it));
                num/=2;
                it++;
            }
        }
        return result;
    }
};