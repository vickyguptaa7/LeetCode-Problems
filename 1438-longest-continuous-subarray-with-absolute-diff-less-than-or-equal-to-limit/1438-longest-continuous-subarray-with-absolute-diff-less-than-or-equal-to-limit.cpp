class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int>freqSort;
        int low=0,high=0,size=nums.size(),res=0;
        while(high<size)
        {
            freqSort[nums[high++]]++;
            
            if(freqSort.rbegin()->first-freqSort.begin()->first>limit)
            {
                res=max(res,high-low-1);
                freqSort[nums[low]]--;
                if(freqSort[nums[low]]==0)
                {
                    freqSort.erase(nums[low]);
                }
                low++;
            }
        }
        res=max(res,high-low);
        return res;
    }
};