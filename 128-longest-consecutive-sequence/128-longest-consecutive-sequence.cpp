class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto x:nums)freq[x]++;
        int n=nums.size();
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(!freq.count(nums[i]-1))
            {
                int count=0,num=nums[i];
                while(freq.count(num))
                {
                    count++;
                    num++;
                }
                res=max(count,res);
            }
        }
        return res;
    }
};