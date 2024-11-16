class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<=n-k;i++)
        {
            int mx=nums[i];
            bool isSorted=true;
            for(int j=i+1;j<i+k;j++)
            {
                if(nums[j-1]+1!=nums[j])
                {
                    isSorted=false;
                    break;
                }
                mx=max(mx,nums[j]);
            }
            result.push_back(isSorted?mx:-1);
        }
        return result;
    }
};