class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        set<int>mset;
        mset.insert(0);
        int sum=0,ans=-1e9;
        for(auto num:nums)
        {
            sum+=num;
            ans=max({ans,abs(sum-*mset.begin()),abs(sum-*mset.rbegin())});
            mset.insert(sum);
        }
        return ans;
    }
};