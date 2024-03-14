class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>freq;
        freq[0]=1;
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(freq.count(sum-goal))res+=freq[sum-goal];
            freq[sum]++;
        }
        return res;
    }
};