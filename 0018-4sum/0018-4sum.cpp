class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>quad;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>oset;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int left=j+1,right=n-1;
                long long curr=target-(long long)(nums[i]+nums[j]);
                while(left<right)
                {
                    if(curr-(nums[left]+nums[right])==0)
                    {
                        quad.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        while(left<right&&nums[left]==nums[left-1])left++;
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