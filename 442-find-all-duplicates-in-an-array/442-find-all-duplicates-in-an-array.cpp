class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // First Way Is To Sort And Find T.C -> O(nlogn)
        // Another Way Is To Use A Map DS For Storing The Freq
        vector<int>res;
        unordered_set<int>uset;
        for(int i=0;i<nums.size();i++)
        {
            if(uset.find(nums[i])!=uset.end())
            {
                res.push_back(nums[i]);
            }
            else
            {
                uset.insert(nums[i]);
            }
        }
        return res;
    }
};