class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        multiset<int>mset;
        int iter=0;
        for(int i=0;i<nums.size();i++)
        {
            while(mset.empty()||(iter<nums.size()&&abs(*mset.begin()-nums[iter])<=2&&(abs(*mset.rbegin()-nums[iter])<=2)))
            {
                mset.insert(nums[iter++]);
            }
            ans+=mset.size();
            mset.erase(mset.find(nums[i]));
        }
        return ans;
    }
};