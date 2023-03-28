class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long>minOper;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>preSum(len+1);
        
        for(int i=1;i<=len;i++)preSum[i]=preSum[i-1]+nums[i-1];
        
        for(auto x:queries)
        {    
            int indx=upper_bound(nums.begin(),nums.end(),x)-nums.begin();
            long long first=(long long)x*indx-preSum[indx];
            long long last=((long long)preSum[len]-preSum[indx]-(long long)x*(len-indx));
            minOper.push_back(first+last);
        }
        return minOper;
    }
};