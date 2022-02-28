class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return {to_string(nums[0])};
        }
        vector<string>res;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]==1)
            {
                string ans=to_string(nums[i-1]);
                while(i<n&&nums[i]-(long long)nums[i-1]==1)
                {
                    i++;
                }
                ans+="->";
                ans+=to_string(nums[i-1]);
                res.push_back(ans);
            }
            else
            {
                res.push_back(to_string(nums[i-1]));
            }
        }
        if(n>=2&&nums[n-1]-(long long)nums[n-2]!=1)
        {
            res.push_back(to_string(nums[n-1]));
        }
        return res;
    }
};