class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int,int>mmp;
        for(auto x:nums)mmp[x]++;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            auto target=mmp.upper_bound(nums[i]);
            if(target!=mmp.end())
            {
                res++;
                mmp[target->first]--;
                if(mmp[target->first]==0)
                {
                    mmp.erase(target->first);
                }
            }
        }
        return res;
    }
};