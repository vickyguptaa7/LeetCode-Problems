class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int Min=0;
        multiset<int>mset(nums.begin()+1,nums.end());
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[Min]>nums[i])
            {
                Min=i;
            }
            mset.erase(mset.find(nums[i]));
            int nk=*mset.upper_bound(nums[Min]);
            if(!mset.count(nk))continue;
            // cout<<nk<<"\n";
            if(nums[Min]<nums[i]&&nk<nums[i]&&nums[Min]<nk)
            {
                cout<<nums[Min]<<" "<<nums[i]<<" "<<nk<<"\n";
                return true;
            }
            
        }
        return false;
    }
};