class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<int,int>freq;
        freq[0]++;
        long long zeroSubCount=0,zeroCnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zeroCnt++;
            }
            else
            {
                zeroSubCount+=(zeroCnt*(zeroCnt+1))/2;
                zeroCnt=0;
            }
        }
        zeroSubCount+=(zeroCnt*(zeroCnt+1))/2;
        return zeroSubCount;
    }
};