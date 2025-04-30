class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto num:nums)
        {
            int len=0,temp=num;
            while(num)
            {
                len++;
                num/=10;
            }
            if(!(len&1))
                count++;
        }
        return count;
    }
};