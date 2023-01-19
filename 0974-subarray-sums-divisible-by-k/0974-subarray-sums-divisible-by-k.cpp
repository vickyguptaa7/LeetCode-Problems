class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int sum=0,ans=0;
        freq[0]=1;
        for(auto x:nums)
        {
            sum+=(x%k)+k;
            sum%=k;
            if(freq.count(sum))
            {
                ans+=freq[sum];
            }
            freq[sum]++;
        }
        return ans;
    }
};