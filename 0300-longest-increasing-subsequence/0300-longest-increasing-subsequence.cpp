class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>help;
        for(int i=0;i<nums.size();i++)
        {
            int indx=lower_bound(help.begin(),help.end(),nums[i])-help.begin();
            if(indx==help.size())
                help.push_back(nums[i]);
            else 
                help[indx]=nums[i];
        }
        return help.size();
    }
};