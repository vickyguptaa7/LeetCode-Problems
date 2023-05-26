class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>quad;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>oset;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int left=j+1,right=n-1;
                long long curr=target-(long long)(nums[i]+nums[j]);
                while(left<right)
                {
                    if(curr-(nums[left]+nums[right])==0
                       &&!oset.count({nums[i],nums[j],nums[left],nums[right]}))
                    {
                        oset.insert({nums[i],nums[j],nums[left],nums[right]});
                        quad.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                    }
                    else if(curr-(nums[left]+nums[right])<0)
                    {
                        right--;
                    }
                    else 
                    {
                        left++;
                    }
                }
            }
        }
        return quad;
    }
};