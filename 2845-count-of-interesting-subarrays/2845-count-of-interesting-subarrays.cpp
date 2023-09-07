class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int>pre(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            pre[i]=(nums[i]%modulo==k);
        }
        pre[0]%=modulo;
        for(int i=1;i<nums.size();i++)
        {
            pre[i]+=pre[i-1];
            pre[i]%=modulo;
        }
        // (x-y)%m=k
        // (x-k)%m=y
        map<int,int>freq;
        long long res=0;
        freq[0]++;
        for(int i=0;i<nums.size();i++)
        {
            int find=(pre[i]-k+modulo)%modulo;
            if(freq.count(find))
                res+=freq[find];
            freq[pre[i]]++;
        }
        return res;
    }
};