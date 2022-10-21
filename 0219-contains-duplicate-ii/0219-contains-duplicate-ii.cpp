class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int>oset;
        for(int i=0;i<nums.size();i++)
        {
            if(oset.size()<k)
            {
                if(oset.count(nums[i]))return true;
                oset.insert(nums[i]);
            }
            else
            {
                if(oset.count(nums[i]))return true;
                oset.insert(nums[i]);
                oset.erase(nums[i-k]);
            }
        }
        return false;
    }
};