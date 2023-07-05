class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>premp;
        int n=nums.size(),sum=0,subCount=0;
        premp[0]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(premp.count(sum-k))
                subCount+=premp[sum-k];
            premp[sum]++;
        }
        return subCount;
    }
};