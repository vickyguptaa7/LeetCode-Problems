class Solution {
public:

    int digitSum(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        map<int,pair<int,int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            int dsum=digitSum(nums[i]);
            if(!mp.count(dsum))
            {
                mp[dsum].first=nums[i];
                mp[dsum].second=-1;
            }
            else if(mp[dsum].first<nums[i])
            {
                mp[dsum].second=mp[dsum].first;
                mp[dsum].first=nums[i];
            }
            else if(mp[dsum].second<nums[i])
            {
                mp[dsum].second=nums[i];
            }
        }
        int ans=-1;
        for(auto &x:mp)
        {
            if(x.second.second==-1)continue;
            ans=max(ans,x.second.first+x.second.second);
        }
        return ans;
    }
};