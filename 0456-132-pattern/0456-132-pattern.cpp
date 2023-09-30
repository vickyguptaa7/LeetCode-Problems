class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        map<int,int>freq;
        
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        
        int mn=1e9+7;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]--;
            if(freq[nums[i]]==0)
                freq.erase(nums[i]);
            
            if(mn>nums[i])
            {
                mn=nums[i];
            }
            else
            {
                auto val=freq.upper_bound(mn);
                if(val==freq.end())continue;
                if(val->first<nums[i])
                    return true;
            }
        }
        return false;
    }
};