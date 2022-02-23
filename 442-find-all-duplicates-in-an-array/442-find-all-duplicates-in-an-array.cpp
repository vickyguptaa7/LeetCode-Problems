class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // First Way Is To Sort And Find T.C -> O(nlogn)
        
        // Another Way Is To Use A Map DS For Storing The Freq
        // vector<int>res;
        // unordered_set<int>uset;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(uset.find(nums[i])!=uset.end())
        //     {
        //         res.push_back(nums[i]);
        //     }
        //     else
        //     {
        //         uset.insert(nums[i]);
        //     }
        // }
        // return res;
        
        // Another Space Optemize Soln Mark Repeated As -ve sign
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                if(nums[-nums[i]-1]<0)
                {
                    res.push_back(-nums[i]);
                }
                else nums[-nums[i]-1]=-nums[-nums[i]-1];
            }
            else
            {
                if(nums[nums[i]-1]<0)
                {
                    res.push_back(nums[i]);
                }
                else nums[nums[i]-1]=-nums[nums[i]-1];
            }
        }
        return res;
    }
};