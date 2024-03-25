class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        for(auto &num:nums)
        {
            if(nums[abs(num)-1]<0)
            {
                res.push_back(abs(num));
            }
            nums[abs(num)-1]=-nums[abs(num)-1];
        }
        for(auto &num:nums)
        {
            num=abs(num);
        }
        return res;
    }
};