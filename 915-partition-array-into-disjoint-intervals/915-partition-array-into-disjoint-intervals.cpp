class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        map<int,int>freq;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            freq[nums[i]]++;
        }
        
        int res=1,Max=nums[0];
        for(int i=1;i<n;i++)
        {
            if(Max>freq.begin()->first)
            {
                freq[nums[i]]--;
                if(freq[nums[i]]==0)freq.erase(nums[i]);
                res++;
                Max=max(Max,nums[i]);
            }
        }
        return res;
    }
};