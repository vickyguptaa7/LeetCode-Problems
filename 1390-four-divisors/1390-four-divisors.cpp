class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++)
        {
            int devisorCount=0, sum=0;
            for(long j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    sum+=j+(nums[i]/j);
                    devisorCount++;
                }
            }
            if(devisorCount==4)totalSum+=sum;
        }
        return totalSum;
    }
};